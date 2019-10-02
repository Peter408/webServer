#include "Worker.hpp"

#include "../http/Request.hpp"
#include "../http/Resource.hpp"
#include "../http/ResponseFactory.hpp"
#include "../http/responses/Response.hpp"
#include "../logger/Logger.hpp"

Worker::Worker() { }

Worker::~Worker() { }

boost::asio::ip::tcp::iostream* Worker::getClient() {
    return &client_;
}

void Worker::run(HttpdConf& httpdConf, MimeTypes& mimeTypes) {
    Request request(client_);
    request.parse();

    Resource resource(request, httpdConf, mimeTypes);
    ResponseFactory factory;
    Response* pResponse = factory.getResponse(request.getVerb(), resource);

    pResponse->send(client_);

    Logger logger(httpdConf.getLog());
    logger.writeLogger(request, pResponse, resource);

    delete this;
}