#include <iostream>
#include "message.pb.h"

namespace {
    using twitch::Piola;
    using std::cout;
    using std::endl;
}

// esta macro es la chida
void mergemaps(const Piola& from, Piola* to) {
#define MERGE_MAPS(FIELD)                               \
    for (const auto& [key, value] : from.FIELD()) {     \
    (*to->mutable_##FIELD())[key] += value;             \
    }

    MERGE_MAPS(boludez);
    MERGE_MAPS(ki);
    MERGE_MAPS(cosmos);
#undef MERGE_MAPS
}

int main() {
    Piola piola;

    auto boludo = piola.mutable_boludez();

    (*boludo)["juancarlospaco"] = 3;
    (*boludo)["unai"] = 2;
    (*boludo)["justiciero"] = 5;

    auto makara = piola.mutable_ki();

    (*makara)["xtarblack"] = 7;
    (*makara)["eddy"] = 11;
    (*makara)["justiciero"] = 13;
    (*makara)["unai"] = 17;
    (*makara)["juancarlospaco"] = 19;

    auto langara = piola.mutable_cosmos();

    (*langara)["erick"] = 4;
    (*langara)["unai"] = 10;
    (*langara)["juancarlospaco"] = 2;

    Piola clean_piola;

    auto bondi = clean_piola.mutable_boludez();
    (*bondi)["juancarlospaco"] = 65;
    (*bondi)["unai"] = 91;
    (*bondi)["erick"] = 73;

    auto masboludo = clean_piola.mutable_ki();
    (*masboludo)["unai"] = 3;

    cout << "=======" << endl;
    cout << piola.DebugString() << endl;
    cout << "=======" << endl;
    cout << clean_piola.DebugString() << endl;
    cout << "=======" << endl;

    mergemaps(piola, &clean_piola);

    cout << "=======" << endl;
    cout << piola.DebugString() << endl;
    cout << "=======" << endl;
    cout << clean_piola.DebugString() << endl;
    cout << "=======" << endl;

    return 0;
}
