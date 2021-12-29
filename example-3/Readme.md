# Steps followed for this example #
1. Write a student.h file and add a function prototype.  
2. Run the following command:  
    soapcpp2 -c++ -r -SL hello.h     
3. Implement service function in helloserver.cpp.  
4. Build codes using following command:  
    c++ -o student studentserver.cpp soapC.cpp soapServer.cpp -l gsoap++  
5. To run the server use following command:  
    ./student        # To run as a CGI-application  
    ./student port   # To run on a specified port  
4. To run test run following command:  
    curl -X POST -d @ns.hello.req.xml http://localhost:8080  