#include "server.hpp"
#include "response_generators.hpp"
#include "session.hpp"
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/bind.hpp>
#include <boost/python.hpp>
#include <boost/python/extract.hpp>
#include <boost/python/import.hpp>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
#include <string>

using boost::asio::ip::tcp;
using nlohmann::json;

#error "Переставить путь к плагинам"

PluginServer::PluginServer(boost::asio::io_context &context, uint16_t port)
    : io_context_(context),
      acceptor_(io_context_, tcp::endpoint(tcp::v4(), port)) {
    Py_Initialize();
    start_accept();
}

void PluginServer::start_accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            // if (!ec) {
            //     auto test = std::make_unique<ResponceGenerator>();
            //     std::make_shared<Session>(std::move(socket), std::move(test))
            //         ->start();
            // }
            // start_accept();
        });
}
