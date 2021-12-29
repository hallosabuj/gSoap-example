# Steps followed for this example #
1. Write a hello.h file and add a function prototype.  
2. Run the following command:  
    soapcpp2 -c++ -r -SL hello.h   
   Above command will generate few xml files, few cpp files, header files and a wsdl file with few xsd files.  
   And above generated wsdl file can be published to client.  
3. Implement service function in helloserver.cpp.  
4. Build codes using following command:  
    c++ -o hello helloserver.cpp soapC.cpp soapServer.cpp -lgsoap++  
5. To run the server use following command:  
    ./hello        # To run as a CGI-application  
    ./hello port   # To run on a specified port  
4. To run test run following command:  
    curl -X POST -d @ns.hello.req.xml http://localhost:8080  