# KNN Vector Classifier - Server and Client
This repository is used to connect a client to a server that classifies a given vector based on a given database and $K$ vectors who are closest to it in distance. The server uses *KNN(K Nearest Neighbors)* algorithm and TCP based transport layer protocols.  
Classifies the vector based on one of these distance formulas:  
1. Euclidean distance  
2. Taxicab geometry  
3. Chebyshev distance  
4. Canberra distance  
5. Minkowski distance (with the parameter *p* equals 2)  

### Downloading files
To run the program, clone the repository from Github using git:  
1. Open a new folder or use an existing one.   
3. In the terminal, clone the repository using this command:  
`git clone https://github.com/NopharGlo/KNN_Server`  
4. Enter the cloned folder and continue with compiling.  

### Compiling and Running
Make sure the terminal is in the directory with the downloaded files.  
In order to compile the files, write the following command in the terminal (make sure g++ compiler is installed): `make`  
From now on, you need to use two terminals or two different computers.  
#### Running the Server
To run the server, in the first terminal type the following command: `./server.out [first argument] [second argument]`, in which the arguments are:  
1. First argument - the name of the **csv** file containing the database. The file must be seperated and stored properly:  
    - The file must exsist and stored within the *same directory* as the code files(or be directed to through a working path as the argument).
    - Each column seperated by `,`, lines seperated by `Enter` key.  
    - The values are all *doubles* **except for the rightmost value** which is a *string* containing the classification of this vector.
    - All the vectors are in the same total length.
    - If empty char will be inserted in the middle of the file the file will be considered invalid input.
2. Second argument - the port for the server to connect to (an integer in the range of $1024 - 65535$, with nothing that is not a digit).  
If the filed was opened correctly and the server was able to connect to the given port, the server will wait for the clients to connect. If there was an error, a relevant message will be printed.

#### Running the Client
To run the client, while the server program is running, in the second terminal type the following command:  
`./client.out [first argument] [second argument]`, in which the arguments are:  
1. First argument - the IP address of the server (must be correct or the client will not be able to connect with the server).
2. Second argument - the port address of the server (like the server, needs to be an integer in the range of $1024 - 65535$, with nothing that is not a digit, and must match to the server's port number for making a correct connection).  
***Every deviation from the instructions above will cause an error and the program to close(e.g. inserting a port number that was not correct).***

### Using the Classifier
Pass the relevant values to the client's program as such: `[vector] [distance] [K]`, with spaces between the three. Each one of it has different properties and restrictions:  
1.  The vector - a sequence of numbers (with spaces [`' '`] between the numbers), containing valid floating point numbers(e.g. `1.4 2 5.2 10.005`).  
    Restrictions on the vector input (that will cause an invalid input message to appear):  
    A. A vector that is not in the same length as the vectors in the database given to the server.  
    B. Vectors containing a non-numerical figure (e.g. trying to insert the vector `1 a 3`).  
    C. Invalid floating points - more than one dot in a number(e.g. `4.4.5 53`). Note that writing no number before/after the dot will be considered as adding 0 accordingly(e.g. `.27` = `0.27`, `.` = `0.0`).  
    D. A `-` not at the beginning of a number (e.g. `45-123 12 32`) and not as a part of an exponent format(e.g. `1E+4` is a valid number).  
    E. A number that is too large to be stored the in vector (in this program, the length of each input was limited to **250** characters, including exponent! which means `1.e±260` for example is *invalid*).  
    F. More than one exponent sign is invalid (e.g. `1e1e1`).  
2. The distance function - the method used to calculate the distance from this vector. There are currently 5 options to choose from, insert the string as presented at the begining of each option to use that distance:  
    - `AUC` for Euclidean distance.  
    - `MAN` for Manhattan distance(Taxicab geometry).  
    - `CHB` for Chebyshev distance.  
    - `CAN` for Canberra distance.  
    - `MIN` for Minkowski distance.  
Not using one of these or emmitting any parameter as such will cause an invalid input to accur.  
3. The $K$ number - the number that determines how many neighbors will be used to classify the vector. Must be a number in the range of $1 ≤ K ≤ n$ where $n$ is the number of members in the vector. Deviating from this will cause an invalid input message to be printed.  
*After inserting the numbers and pressing the `Enter` key, if the numbers are valid, the classification will be printed on screen and the program will wait for a new vector to be inserted.*  
**NOTE: THE OVERALL LENGTH OF THE INPUT CAN BE AS HIGH AS 4096 CHARACTERS, BUT NOT MORE - diverting from this will cause invalid input message.**  

### Client and Server Connection
After the synchronization and basic connection between the client and the server, everytime the client will send the inserted vector to the server, the server will classify it based on its database and based on the distance and K given to him by the client.  
The client will be able to send as many vectors as needed without losing the connection to the server (excluding technical issues).  
The server will not handle more than one client simultaniously - only after a client had been closed, the server will go on to the next client.  
In order for the client to close the connection and the program, simply enter: `-1` as the input to the client and the client program will shut down, while the server will continue to wait for another client.  

## Implementation
The project was implemented with a variety of classes, each responsible for different things, e.g. certain distances, vector validity checking and appliying the Select algorithm.  
The *Client* class is responsible of connecting the user to the server, taking his input, checking it using the *ClientVectorCheck* class and passing it through to the server. The client will check the validity related to it - making sure the vector is valid, the K num is valid etc.  
The *Server* class is responsible of opening the database and read from it, setting up the server and making sure the client gets the proper classification. It is also responsible for checking the validity related to it - making sure that the distance function received is valid and the K is not bigger than the database.   
The *Distance* classes(such as *CanberraDistance*) were based on the distance formulas from the first exercise, all inhereting from a single class - Distance.  
The complex mathematical functions of these classes' functions (e.g. `sqrt()`, `pow()`) were imported from the `cmath` class.  
The *VectorCheck* class is responsible for verifying the validity of the string vectors/inputs and converting it to double vectors.  
The *Database* class is the class representing the data structure that holds everything together - a vector of doubles with specifications based on the file, a string containing the classificatin and the distance itself calculated for the inserted vector(this one varies from input to input).  
The *SelectSort* class responsible to take the distances of the vectors and sorting it using the Select algorithm, which outputs the $K$ lowest numbers in the begining of the vector in $O(n)$ time.  
The strings were inserted using the `sstream` class and the `getline()` function, and seperated to numeric values using the `getline()` function.  
The program can deal with multiple space characters at the beginning, ending and in the middle of the string, and with floating point numbers (integers included, as long as it is valid and under 250 characters total).

