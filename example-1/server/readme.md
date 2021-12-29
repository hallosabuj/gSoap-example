1. Generate the service and data binding interface for the server side with:
    soapcpp2 -c -r -SL calc.h   
2. To build the example server application we also need stdsoap2.h and stdsoap2.c:
    c++ -o calcserver calcserver.cpp soapC.cpp soapServer.cpp -l gsoap++
3. To run the server use following command:
    ./calcserver        # To run as a CGI-application
    ./calcserver port   # To run on a specified port