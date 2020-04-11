#include <drogon/drogon.h>
using namespace drogon;
auto main() -> int {
    app().loadConfigFile("../config.json").run();
    return 0;
}
