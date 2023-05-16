# Port Scanner

A simple port scanner written in C++ that checks for open ports within a specified range on a target host.

## Features

- **Multithreaded Scanning:** Concurrently scans multiple ports using threads for faster scanning.
- **Range of Ports:** Allows you to specify a range of ports to scan for the target IP address.
- **Open Port Detection:** Detects and displays the open ports found during the scan.
- **Scan Summary:** Provides a summary of the scan results, including the number of open and closed ports.

## Libraries Used

- `iostream`: Provides input/output streams functionality.
- `string`: Enables string manipulation and operations.
- `vector`: Implements dynamic arrays (vectors) and provides related functions.
- `thread`: Supports multithreading and manages concurrent execution.
- `mutex`: Provides a synchronization primitive (mutex) to protect shared resources.
- `chrono`: Offers functions to measure time durations and delays.
- `sys/socket.h`: Includes socket-related functions and structures.
- `arpa/inet.h`: Contains functions for manipulating IP addresses and network operations.
- `unistd.h`: Provides access to POSIX operating system API.


## Prerequisites

- C++ compiler (e.g., g++)
- Linux-based operating system (e.g., Kali Linux)

## How to Use

1. Clone the repository:

   ```bash
   git clone https://github.com/Janith-Sandamal/port-scanner.git
   ```
2. Navigate to the project directory
```bash
cd port-scanner
```

3. Compile the source code:

  ```bash
g++ port_scanner.cpp -o port_scanner
  ```
4. Run the program:

```bash
./port_scanner
```

Enter the target IP address and the range of ports to scan when prompted.

Wait for the scanning process to complete. The program will display the open ports in a table format and provide a summary of the scan results.
<br>
<p align="center">
  <img src="https://github.com/Janith-Sandamal/network-scanner/assets/78975250/8558b0a4-904a-4b7e-be9f-18bbaf403c81" alt="Banner" width="500" height="300">
</p>



## License
This project is licensed under the MIT License. See the <a href="https://github.com/Janith-Sandamal/port-scanner/blob/main/LICENSE">LICENSE<a/> file for details.

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request.

## Contact 
<p align="center">Made with ❤️ by Janith Sandamal</p>


## Disclaimer
Please ensure that you have the necessary permissions and adhere to applicable laws and regulations before scanning any network or system. The authors of this project are not responsible for any unauthorized or illegal usage of the network scanner.
