#include <iostream>
#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

using namespace std;

int main() {

    try
    {
        string url = "http://localhost/cache/Hello";
        // RAII cleanup
        curlpp::Cleanup cURLppStartStop;
        curlpp::Easy post;

        post.setOpt(curlpp::options::Url(url));
        post.setOpt(new curlpp::options::CustomRequest{"PUT"});
        post.setOpt(new curlpp::options::PostFields ("World"));
        post.setOpt(curlpp::options::Port(8080));
        post.perform();

        curlpp::Easy get;
        get.setOpt(curlpp::options::Url(url§));
        std::stringstream response;
        get.setOpt(new curlpp::options::WriteStream(&response));
        get.setOpt(curlpp::options::Port(8080));
        get.perform();

        cout << "Hello = " << response.str() << endl;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }
}
