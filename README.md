# KNN Vector Classifier - Multiple Clients
This repository is used to connect multiple clients to a server that classifies a file of vectors based on a database uploaded by the client to the server. Each client can choose the number of vectors ( $K$ ) who are closest to it in distance and be calculated by, and the distance metric. The server uses *KNN(K Nearest Neighbors)* algorithm and TCP based transport layer protocols.  
Classifies the vectors based on one of these distance formulas(or *metrics*):  
1. Euclidean distance  
2. Taxicab geometry  
3. Chebyshev distance  
4. Canberra distance  
5. Minkowski distance (with the parameter $p$ equals $2$)  

### Downloading the Files
To run the program, clone the repository from Github using git:  
1. Open a new folder or use an existing one.   
3. In the terminal, clone the repository using this command:  
`git clone https://github.com/ShlomiShatz/Classifier_Server`  
4. Enter the cloned folder and continue with compiling.  

### Compiling and Running
Make sure the terminal is in the directory with the downloaded files and folders.  
In order to compile the files, write the following command in the terminal (make sure g++ compiler is installed): `make`  
From now on, you need to use one terminal for the server and different terminals/computers for the clients.  
#### Running the Server
To run the server, in the first terminal type the following command: `./server.out [argument]`, in which the argument is the port for the server to connect to (an integer in the range of $1024 - 65535$, with nothing that is not a digit).  
If the filed was opened correctly and the server was able to connect to the given port, the server will wait for the clients to connect. If there was an error, a relevant message will be printed.

#### Running the Clients
To run each client, while the server program is running, in a seperate terminal/computer type the following command:  
`./client.out [first argument] [second argument]`, in which the arguments are:  
1. First argument - the IP address of the server (must be correct or the client will not be able to connect with the server).
2. Second argument - the port address of the server (like the server, needs to be an integer in the range of $1024 - 65535$, with nothing that is not a digit, and must match to the server's port number for making a correct connection).  
***Every deviation from the instructions above will cause an error and the program to close(e.g. inserting a port number that was not correct).***

### Using the Classifier
Upon running the client with the proper arguments and connecting to the server, the client will see the main menu of the server:  
![image](https://user-images.githubusercontent.com/86709272/214510845-9d9c6bea-2335-441a-b26a-1e0cea4defa3.png)  
Right now, the server waits for the client to choose an option. The options are `1 - 5, 8`, and the client should reply using *ONLY* the number of option(No letters/spaces etc.). If a correct option was entered, the server will response accordingly(details below), otherwise - an `invalid input` message will be sent by the server. The options are:  
1.  Uploading the necessary data - entering `1` as an answer, will be followed by a message requesting to upload the classified data file that will be the database for further classifications(a 'train' file): `Please upload your local train CSV file.`  
    The client will now need to enter a *VALID* path to an *existing* CSV file, which contains classified vectors and follows these rules:
    - Each column seperated by `,`, lines seperated by `Enter` key.  
    - The values are all *doubles* **except for the rightmost value** which is a *string* containing the classification for this vector.  
    - All the vectors are in the same total length.  
    - If empty char will be inserted in the middle of the file the file will be considered invalid input.  
    - The first line of the file mush contain a vector and not be empty.  
    If an invalid path/file was entered, an `invalid input` message will be printed and the client will go back to the main menu.  
    
    If a valid file was uploaded, the message `Upload complete.` will be printed, followed by: `Please upload your local test CSV file.`, asking for a path to an  *unclassified CSV file* that will be classified(a 'test' file). The path has the same restrictions as the last one. The unclassified CSV file needs to be made as such:  
    - Each column seperated by `,`, lines seperated by `Enter` key.  
    - The values are all *doubles*, and **NO** classification. 
    - All the vectors are in the same total length, and the total length of the vector is $-1$ the size of the classified file's vectors(No classifications this time).  
    - If empty char will be inserted in the middle of the file the file will be considered invalid input.  
    - The first line of the file mush contain a vector and not be empty.  
    If an invalid path/file(such as a classified file) was entered, an `invalid input` message will be printed and the client will go back to the main menu. The first uploaded file will need to be uploaded again and will NOT be saved in the server.  
    If a valid file was uploaded, the message `Upload complete.` will be printed and the client will be brought back to the main menu.  
    ***NOTE: If an invalid file/path was entered at each of the two times, ALL THE DATA IN THE SERVER WILL BE RESET. Meanning - if a file was uploaded correctly and then an invalid one was - both of them will be needed to be uploaded again. Furthermore - if valid files were uploaded and the client entered `1` again in the main menu, the necessary files will need to be uploaded again(can be different files) and bad input will cause the old files to be deleted from the server.***
    
    Further restrictions on each vector in the file (that will cause an invalid input message to appear):   
    * Vectors containing a non-numerical figure (e.g. trying to insert the vector `1,a,3`).  
    * Invalid floating points - more than one dot in a number(e.g. `4.4.5,53`). Note that writing no number before/after the dot will be considered as adding 0 accordingly(e.g. `.27` = `0.27`, `.` = `0.0`).  
    * A `-` not at the beginning of a number (e.g. `45-123,12,32`) and not as a part of an exponent format(e.g. `1E+4` is a valid number).  
    * A number that is too large to be stored the in vector (in this program, the length of each vector was limited to **250** characters, including exponent! which means `1.e±260` for example is *invalid*).  
    * More than one exponent sign is invalid (e.g. `1e1e1`).  
    
2. The algorithm settings - the method used to define the settings for this classification. After entering `2` as the option chosen, the server will send the current settings of the classification, which by default are: `The current KNN parameters are: K = 5, distance metric = AUC`(The metric options explanation are below). If you are the client and wish to change these settings, just enter two parameters seperated by space: `[K value] [Metric]`. Note that entering more than two parameters will cause an `invalid input` message. The restrictions for the parameters are:  
    I. The K value - this will determine the number of closest neighbors to be classified by. It must be a natural number in the range of $1 ≤ K ≤ n$ where $n$ is the number of vectors in the database. Deviating from this will cause an `invalid value for K` message to be printed. The default value is 5. Note - the K cannot be changed until the data files were uploaded.    
    II. The metric - this will determine the specific way to calculate the distance between the vectors. There are currently 5 options to choose from, insert the string as presented at the begining of each option to use that distance:  
    - `AUC` for Euclidean distance(The default metric).  
    - `MAN` for Manhattan distance(Taxicab geometry).  
    - `CHB` for Chebyshev distance.  
    - `CAN` for Canberra distance.  
    - `MIN` for Minkowski distance.  
    Not using one of these will cause an `invalid value for metric` message to be printed.
    If both of the parameters are wrong, both of the error message will be printed.  
    After entering the parameters, the client will be brought back to the main menu. Note: if you do not wish to change the current settings, just hit `Enter` and you will be brought back to main menu.  
    
3. Classifying the data - choosing the third option will classify the uploaded data. after classification(in larger files might take some time), the message `classifying data complete` will be printed and the client will return to the main menu. Note - the client MUST upload the data correctly before trying to classify it, or the message `please upload data` will be printed.  

4. Displaying the classified data - choosing the fourth option will print the classified data, based on the unclassified vectors by numeric order, followed by a `Done.` message. For example:  
![image](https://user-images.githubusercontent.com/86709272/214524200-d06bfc96-d088-41a2-9931-a92138c1c1fb.png)  
The left column is the number of vector, and on the right is the resulted classification. In order to return to the main menu, simply hit `Enter`. Note - the data must be uploaded *and* classified before this option can be chosen, or an appropriate message will be printed.  

5. Downloading the classified data - choosing the fifth option will download the classified data as ordered in the fourth option to a file at the client's computer. After entering `5` as an option, the server will expect the client to enter a valid path to an existing directory, *ended by the wished name of the created file including the type of it(e.g. `.txt`)*. Note - a path to an existing file will cause the file to be overwritten. If the client wishes to create the file in the working directory, simply enter the name of the file without path. After entering the path and file name, if valid, a file will be created on the clients computer, containing the data as shown in the fourth option. While the data is downloaded, the client will be able to continue using the menu. Note - the same rule applies here - the data must be uploaded *and* classified before this option can be chosen, or an appropriate message will be printed(due to multithreading, the message might be sent at a later time).  

8. Exit - this option(`8`) will cause the client to exit the program and finishing it. The server will keep running, waiting for clients.

### Client and Server Connection
This program uses multithreading. The connection between the server and the clients is made with TCP sockets and threads. Each client wishes to connect to the server, will have a seperate ditached thread and will be seperated from the rest of the clients - having his own classification files and settings. After the synchronization and basic connection between the client and the server, the main menu will be printed and used as needed without losing the connection to the server (excluding technical issues). If a client will choose to exit, his socket and thread will be closed, not affecting the rest of the connected clients. The server will keep running.

## Implementation
The project was implemented with a variety of classes, each responsible for different things, e.g. certain distances, vector validity checking and appliying the Select algorithm.  
The *Client* class is responsible of connecting the user to the server, taking his input, and communicating with him.  
The *Server* class is responsible of starting the server, waiting for clients to connect and creating threads for each client.  
The *DefaultIO* including *SocketIO* and *StandartIO* classes are resposible of sending the message from the client to the server and back, and printing the data aswell as taking input.
The *CLI* class if responsible for the commandline interface, sending the menu and activating the needed command each time.  
The *Command* class as well as the rest of the commands classes are responsible for applying the needed command.
The *Distance* classes(such as *CanberraDistance*) were based on the distance formulas from the first exercise, all inhereting from a single class - Distance.  
The complex mathematical functions of these classes' functions (e.g. `sqrt()`, `pow()`) were imported from the `cmath` class.  
The *VectorCheck* class is responsible for verifying the validity of the string vectors/inputs and converting it to double vectors.  
The *Database* class is the class representing the data structure that holds everything together - a vector of doubles with specifications based on the file, a string containing the classificatin and the distance itself calculated for the inserted vector(this one varies from input to input).  
The *SelectSort* class responsible to take the distances of the vectors and sorting it using the Select algorithm, which outputs the $K$ lowest numbers in the begining of the vector in $O(n)$ time.  
