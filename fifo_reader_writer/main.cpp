#include <fcntl.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
int main(int argc, char** argv)
{
      std::ifstream file(argv[1], std::ios::binary); // Open the file in binary mode


    const char *fifoPath = "/tmp/virtual_mic"; // Replace with the path to your FIFO

    int fd = open(fifoPath, O_WRONLY); // Open the FIFO for writing
	if (fd == -1) 
	{
		std::cout << "Failed to open fifo" << std::endl;
		exit(1);
	}

    if (file.is_open()) {
	    while(true)
        {
            // Read a specified number of bytes into a buffer
            const int BUFFER_SIZE = 320;
            char buffer[BUFFER_SIZE];
            file.read(buffer, BUFFER_SIZE);

            // Get the actual number of bytes read
            std::streamsize bytesRead = file.gcount();

            // Process the content of the buffer here
            ssize_t bytesWritten = write(fd, buffer, BUFFER_SIZE);
            if (bytesWritten == -1) {
	            std::cout << "error writing into fifo " << std::endl;
	            exit(2);
            }
            else
            {
                usleep(10000);
            }
        }
        file.close(); // Close the file when done
    } else {
        std::cerr << "Error opening the file." << std::endl;
    }
}
