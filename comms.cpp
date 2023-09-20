#include <sdbusplus/async.hpp>
#include <sdbusplus/bus/match.hpp>

#include <cstdlib>
#include <sstream>
#include <string>

int httpGet(const char* host, const char* port, const char* target);

auto signals(sdbusplus::async::context& context) -> sdbusplus::async::task<>
{
    std::string signal = "type='signal',";
    std::string path = "/foo/bar/hello";
    std::string interface = "foo.bar.hello";
    std::string member = "hello";

    namespace rule = sdbusplus::bus::match::rules;
    std::string_view hello = signal.append(rule::path(path))
                                 .append(rule::interface(interface))
                                 .append(rule::member(member));
    auto match = sdbusplus::async::match(context, hello);

    std::string message = "start";
    while ("stop" != message)
    {
        message = co_await match.next<std::string>();
        httpGet("localhost", "443", message.c_str());
    }

    context.request_stop();
}

int main(int argc, char* argv[])
{
    if (!argc || nullptr == argv)
        return 1;

    sdbusplus::async::context context;
    context.spawn(signals(context));
    context.run();

    return 0;
}

