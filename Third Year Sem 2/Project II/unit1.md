# Node JS

## Stream

Stream are object that let you read data from source or write data to designation in continous fashion

Four types of streams

Readable: This stream is used for read operations. It allows you to read data from a source (such as a file or a network connection) in chunks

Writable: This stream is used for write operations. It allows you to write data to a destination (such as a file or a network connection) in chunks

Duplex: This stream can be used for both read and write operations. It allows you to read data from one source and write it to another destination simultaneously

Transform: This stream is a special type of duplex stream that can modify or transform the data as it is written or read. It allows you to apply some logic or function on the data chunks before passing them along. For example, you can use the zlib.createGzip() method to create a transform stream that compresses data using gzip algorithm

## File System

fs module is used for file I/O

```javascript
const fs = require('fs');
```

fs.readFile(): This method reads the content of a file asynchronously and invokes a callback function with the data or error

fs.writeFileSync(): This method writes data to a file synchronously and throws an error if any occurs

fs.appendFile(): This method appends data to a file asynchronously and invokes a callback function with an error if any occurs

fs.unlink(): This method deletes a file asynchronously and invokes a callback function with an error if any occurs

fs.createReadStream(): This method creates a readable stream from a file that allows you to read data in chunks using events or pipes

fs.createWriteStream(): This method creates a writable stream to a file that allows you to write data in chunks using events or pipes

## Node modules

Buffer: This module provides a way of handling streams of binary data. A buffer is a temporary memory in RAM that stores a block of data and sends it for processing when it is full

Console: This module provides a simple debugging console that is similar to the JavaScript console mechanism provided by web browsers. You can use methods such as console.log(), console.error(), and console.warn() to write to any Node.js stream

DNS: This module enables name resolution, which means looking up IP addresses of host names. For example, you can use dns.lookup() to resolve a domain name to an IP address using the operating system facilities

Domain: This module is deprecated since Node.js v4.0.0 and should not be used in new code. It provides a way of grouping multiple I/O operations into a single unit called a domain. Domains can handle errors and clean up resources more easily than using individual event listeners or callbacks

Net: This module provides an asynchronous network API for creating stream-based TCP or IPC servers and clients. You can use net.createServer() to create a server that listens for incoming connections and emits events for handling them. You can also use net.createConnection() to create a client that connects to a server and communicates with it using streams

OS: This module provides various operating system-related utility methods and properties. You can use os.platform() to get the operating system platform, os.cpus() to get information about the CPU cores, os.freemem() to get the amount of free system memory, etc
