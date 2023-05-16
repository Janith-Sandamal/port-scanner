#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


std::mutex outputMutex;
std::vector<int> openPorts;

//This is the function that will be called by each thread to scan a port for the target IP address and add it to the openPorts vector if it is open.
void scanPort(const std::string& targetIP, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::lock_guard<std::mutex> lock(outputMutex);
        std::cerr << "Failed to create socket for port " << port << std::endl;
        return;
    }

    sockaddr_in targetAddress{};
    targetAddress.sin_family = AF_INET;
    targetAddress.sin_port = htons(port);
    if (inet_pton(AF_INET, targetIP.c_str(), &(targetAddress.sin_addr)) <= 0) {
        std::lock_guard<std::mutex> lock(outputMutex);
        std::cerr << "Invalid address or address not supported for port " << port << std::endl;
        close(sock);
        return;
    }

    if (connect(sock, reinterpret_cast<sockaddr*>(&targetAddress), sizeof(targetAddress)) < 0) {
        std::lock_guard<std::mutex> lock(outputMutex);
       // std::cout << "Port " << port << " closed" << std::endl;
    } else {
        std::lock_guard<std::mutex> lock(outputMutex);
        //std::cout << "Port " << port << " open" << std::endl;
        openPorts.push_back(port);
        close(sock);
    }
}

int main() {
    std::string targetIP;
    std::cout << "Enter the target IP address: ";
    std::cin >> targetIP;

    int startPort, endPort;
    std::cout << "Enter the range of ports to scan (start end): ";
    std::cin >> startPort >> endPort;

    std::vector<std::thread> threads;

    for (int port = startPort; port <= endPort; ++port) {
        threads.emplace_back(scanPort, targetIP, port);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "\n----- Open Ports -----" << std::endl;
    if (openPorts.empty()) {
        std::cout << "No open ports found." << std::endl;
    } else {
        std::cout << "Port\tStatus" << std::endl;
        for (int port : openPorts) {
            std::cout << port << "\tOpen" << std::endl;
        }
    }

    std::cout << "\nScan Summary:" << std::endl;
    std::cout << "Open Ports: " << openPorts.size() << std::endl;
    std::cout << "Closed Ports: " << (endPort - startPort ) - openPorts.size() << std::endl;

    return 0;
}
