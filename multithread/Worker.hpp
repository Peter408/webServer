#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>

#include <boost/asio.hpp>

#include "../configuration/HttpdConf.hpp"
#include "../configuration/MimeTypes.hpp"


class Worker {
public:
    Worker();
    ~Worker();
    void run(HttpdConf&, MimeTypes&);
    boost::asio::ip::tcp::iostream* getClient();

private:
    boost::asio::ip::tcp::iostream client_;
};

#endif