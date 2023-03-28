#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

enum Status
{
    Continue              = 100,
    OK                    = 200,
    Created               = 201,
    Accepted              = 202,
    Bad_Request           = 400,
    Unauthorized          = 401,
    Not_Found             = 404,
    Method_Not_Allowed    = 405,
    Internal_Server_Error = 500,
    Not_Implemented       = 501,
    Bad_Gateway           = 502
};

string string_representation(int value){
    if (value == Status::Continue) return "Continue";
    if (value == Status::OK) return "OK";
    if (value == Status::Created) return "Created";
    if (value == Status::Accepted) return "Accepted";
    if (value == Status::Bad_Request) return "Bad Request";
    if (value == Status::Unauthorized) return "Unauthorized";
    if (value == Status::Not_Found) return "Not Found";
    if (value == Status::Method_Not_Allowed) return "Method_Not_Allowed";
    if (value == Status::Internal_Server_Error) return "Internal Server Error";
    if (value == Status::Not_Implemented) return "Not Implemented";
    if (value == Status::Bad_Gateway) return "Bad Gateway";
}

int main(){
    int value;
    cin >> value;
    while (value != 0){
        cout << string_representation(value) << endl;
        cin >> value;
    }
    return 0;
}

