#include "Parse.h"

bool to_bool(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    if (jsonstr == "true") {
        return true;
    } else {
        return false;
    }
}

long to_long(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stol(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}

int to_int(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stoi(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}

double to_double(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stod(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}

Handling getHandling(nlohmann::json const &json) {
    auto handling = Handling(
            to_int(json["arr"]),
            to_int(json["das"]),
            to_int(json["dcd"]),
            to_int(json["sdf"]),
            to_bool(json["safelock"]),
            to_bool(json["cancel"]),
            to_bool(json["may20g"])
    );
    return handling;
}

PointsExtra getPointsExtra(nlohmann::json const &json) {
    auto pointsExtra = PointsExtra(to_string(json["vs"]));
    return pointsExtra;
}

Points getPoints(nlohmann::json const &json) {
    auto points = Points(
            to_int(json["primary"]),
            to_double(json["secondary"]),
            to_double(json["tertiary"]),
            getPointsExtra(json["extra"])
    );
    return points;
}

std::vector<double> getArr(nlohmann::json const &fulljson){

}

AvgTracking getAvgTracking(nlohmann::json const &json) {
    auto avgtracking = AvgTracking();

    return avgtracking;
}

Replay getReplay(nlohmann::json const &json) {
    auto replay = Replay(); //0 fields
    return replay;
}

Source getSource(nlohmann::json const &json) {
    auto source = Source(); //0 fields
    return source;
}

Objective getObjective(nlohmann::json const &json) {
    auto objective = Objective(to_string(json["type"]));
    return objective;
}

Minoskin getMinoskin(nlohmann::json const &json) {
    auto minoskin = Minoskin(
            to_string(json["z"]),
            to_string(json["l"]),
            to_string(json["o"]),
            to_string(json["s"]),
            to_string(json["i"]),
            to_string(json["j"]),
            to_string(json["t"]),
            to_string(json["other"])
    );
    return minoskin;
}

Constants_overrides getConstants_overrides(nlohmann::json const &json) {
    auto constants_overrides = Constants_overrides();
    return constants_overrides;
}

Time getTime(nlohmann::json const &json) {
    auto time = Time(
            to_int(json["start"]),
            to_bool(json["zero"]),
            to_bool(json["locked"]),
            to_int(json["prev"]),
            to_int(json["framoffset"])
    );
    return time;
}

Clears getClears(nlohmann::json const &json) {
    auto clears = Clears(
            to_int(json["singles"]),
            to_int(json["doubles"]),
            to_int(json["triples"]),
            to_int(json["quads"]),
            to_int(json["pentas"]),
            to_int(json["realtspins"]),
            to_int(json["minitspins"]),
            to_int(json["minitpinsingles"]),
            to_int(json["tspinsingles"]),
            to_int(json["minitspindoubles"]),
            to_int(json["tspindoubles"]),
            to_int(json["tspintriples"]),
            to_int(json["tspinquads"]),
            to_int(json["tspinpentas"]),
            to_int(json["allclear"])
    );
    return clears;
}

Garbage getGarbage(nlohmann::json const &json) {
    auto garbage = Garbage(
            to_int(json["sent"]),
            to_int(json["received"]),
            to_int(json["attack"]),
            to_int(json["cleared"])
    );
    return garbage;
}

Finesse getFinesse(nlohmann::json const &json) {
    auto finesse = Finesse(
            to_int(json["combo"]),
            to_int(json["faults"]),
            to_int(json["perfectpieces"])
    );
    return finesse;
}

Hold getHold(nlohmann::json const &json) {
    auto hold = Hold(
            to_string(json["piece"]),
            to_bool(json["locked"])
    );
    return hold;
}

Options getOptions(nlohmann::json const &json) {
    auto options = Options(
            to_int(json["version"]),
            to_bool(json["seed_random"]),
            to_double(json["g"]),
            to_bool(json["countdown"]),
            to_int(json["countdown_count"]),
            to_int(json["countdown_interval"]),
            to_int(json["precountdown"]),
            to_int(json["prestart"]),
            to_string(json["mission"]),
            to_string(json["mission_type"]),
            to_string(json["zoominto"]),
            to_string(json["slot_counter1"]),
            to_string(json["slot_counter2"]),
            to_string(json["slot_counter3"]),
            to_string(json["slot_counter5"]),
            to_string(json["slot_bar1"]),
            to_bool(json["display_fire"]),
            to_bool(json["display_username"]),
            to_bool(json["hasgarbage"]),
            to_bool(json["bgmnoreset"]),
            to_bool(json["neverstopbgm"]),
            to_bool(json["display_next"]),
            to_bool(json["display_hold"]),
            to_bool(json["infinite_hold"]),
            to_int(json["gmargin"]),
            to_double(json["gincrease"]),
            to_int(json["garbagecap"]),
            to_int(json["garbagecapincrease"]),
            to_int(json["garbagecapmax"]),
            to_bool(json["garbageabsolutecap"]),
            to_int(json["garbageholesize"]),
            to_bool(json["garbagephase"]),
            to_bool(json["garbagequeue"]),
            to_int(json["garbageare"]),
            to_string(json["garbageentry"]),
            to_string(json["garbageblocking"]),
            to_string(json["garbagetargetbonus"]),
            to_string(json["presets"]),
            to_string(json["bagtype"]),
            to_string(json["spinbonuses"]),
            to_string(json["combotable"]),
            to_string(json["kickset"]),
            to_int(json["nextcount"]),
            to_bool(json["allow_harddrop"]),
            to_bool(json["display_shadow"]),
            to_int(json["locktime"]),
            to_int(json["garbagespeed"]),
            to_int(json["forfeit_time"]),
            to_int(json["are"]),
            to_int(json["lineclear_are"]),
            to_bool(json["infinitemovement"]),
            to_int(json["lockresets"]),
            to_bool(json["allow180"]),
            getObjective(json["objective"]),
            to_bool(json["room_handling"]),
            to_int(json["room_handling_arr"]),
            to_int(json["room_handling_das"]),
            to_int(json["room_handling_sdf"]),
            to_bool(json["manual_allowed"]),
            to_bool(json["b2bchaining"]),
            to_bool(json["allclears"]),
            to_bool(json["clutch"]),
            to_bool(json["nolockout"]),
            to_string(json["passthrough"]),
            to_bool(json["can_undo"]),
            to_bool(json["can_retry"]),
            to_bool(json["retryisclear"]),
            to_bool(json["noextrawidth"]),
            to_bool(json["stride"]),
            to_int(json["boardwidth"]),
            to_int(json["boardheight"]),
            to_bool(json["new_payback"]),
            to_int(json["messiness_change"]),
            to_int(json["messiness_inner"]),
            to_bool(json["messiness_nosame"]),
            to_int(json["messiness_timeout"]),
            to_bool(json["usebombs"]),
            to_string(json["song"]),
            to_string(json["latencypreference"]),
            getHandling(json["handling"]),
            to_int(json["fulloffset"]),
            to_int(json["fullinterval"]),
            to_string(json["gameid"]),
            to_string(json["username"]),
            getConstants_overrides(json["constantsoverrides"]),
            to_bool(json["gravitymax20g"]),
            to_bool(json["garbageattackcap"]),
            to_bool(json["nosound"]),
            to_bool(json["shielded"]),
            to_int(json["boardbuffer"]),
            to_int(json["survival_cap"]),
            to_int(json["survival_timer_itv"]),
            to_int(json["survival_layer_min"]),
            getMinoskin(json["minoskin"]),
            to_string(json["ghostskin"]),
            to_string(json["boardskin"])
            );

    return options;
}


Stats getStats(nlohmann::json const &json) {
    auto stats = Stats(
            to_long(json["seed"]),
            to_int(json["lines"]),
            to_int(json["level_lines"]),
            to_int(json["level_lines_needed"]),
            to_int(json["inputs"]),
            to_int(json["holds"]),
            getTime(json["time"]),
            to_int(json["score"]),
            to_int(json["zenlevel"]),
            to_int(json["zenprogress"]),
            to_int(json["level"]),
            to_int(json["combo"]),
            to_int(json["btb"]),
            to_int(json["topbtb"]),
            to_int(json["currentbtbchainpower"]),
            to_int(json["tspins"]),
            to_int(json["piecesplaced"]),
            getClears(json["clears"]),
            getGarbage(json["garbage"]),
            to_int(json["kills"]),
            getFinesse(json["finesse"])
            );
    return stats;
}


Controlling getControlling(nlohmann::json const &json) {
    auto controlling = Controlling(
            to_int(json["ldas"]),
            to_int(json["ldasiter"]),
            to_bool(json["lshift"]),
            to_int(json["rdas"]),
            to_int(json["rdasiter"]),
            to_bool(json["rshift"]),
            to_int(json["lastshift"]),
            to_bool(json["softdrop"])
            );

    return controlling;
}

Falling getFalling(nlohmann::json const &json) {
    auto falling = Falling(
            to_bool(json["sleep"]),
            to_bool(json["deep_sleep"]),
            to_bool(json["hibernated"]),
            to_int(json["locking"]),
            to_int(json["lockresets"]),
            to_bool(json["forcelock"]),
            to_bool(json["floored"]),
            to_bool(json["clamped"]),
            to_int(json["safelock"]),
            to_int(json["x"]),
            to_int(json["y"]),
            to_int(json["r"]),
            to_string(json["type"]),
            to_int(json["highesty"]),
            to_string(json["last"]),
            to_int(json["lastkick"]),
            to_string(json["lastrotation"]),
            to_int(json["irs"]),
            to_bool(json["ihs"]),
            to_int(json["aox"]),
            to_int(json["aoy"]),
            to_int(json["keys"])
            );
    return falling;
}

std::vector<Enemy> getEnemy(nlohmann::json const &fulljson) {
    auto enemy = std::vector<Enemy>();
    nlohmann::json json;
    int i = 0;
    while (i < fulljson.size()) {
        json = fulljson[i];
        enemy.push_back(Enemy());
        i++;
    }
    return enemy;
}

std::vector<Target> getTarget(nlohmann::json const &fulljson) {
    auto target = std::vector<Target>();
    nlohmann::json json;
    int i = 0;
    while (i < fulljson.size()) {
        json = fulljson[i];
        target.push_back(Target());
        i++;
    }
    return target;
}

Int_Data getIntData(nlohmann::json const &json) {
    auto intData = Int_Data(
            to_int(json["iid"]),
            to_string(json["type"]),
            to_int(json["amt"]),
            to_int(json["ackiid"]),
            to_int(json["x"]),
            to_int(json["y"]),
            to_int(json["size"]),
            to_string(json["username"])
            );
    return intData;
}

igeData getIgeData(nlohmann::json const &json) {
    auto igedata = igeData(
            to_string(json["type"]),
            to_string(json["gameid"]),
            getTarget(json["targets"]),
            to_int(json["frame"]),
            to_bool(json["value"]),
            to_string(json["key"]),
            to_bool(json["hoisted"]),
            to_int(json["subframe"]),
            getIntData(json["data"])
            );
    return igedata;
}

std::vector<std::string> getRow(nlohmann::json const &json) {

    auto row = std::vector<std::string>();
    nlohmann::json ison;
    int i = 0;
    while (i < json.size()) {
        ison = json[i];
        row.push_back(to_string(ison));
        i++;
    }
    return row;

}

std::vector<BoardV> getBoardV(nlohmann::json const &fulljson) {
    auto boardV = std::vector<BoardV>();
    nlohmann::json json;
    int i = 0;
    while (i < fulljson.size()) {
        json = fulljson[i];
        boardV.push_back(BoardV(getRow(json)));
        i++;
    }
    return boardV;
}

std::vector<std::string> getBag(nlohmann::json const &fulljson) {
    auto bag = std::vector<std::string>();
    nlohmann::json json;
    int i = 0;
    while (i < fulljson.size()) {
        json = fulljson[i];
        bag.push_back(to_string(json));
        i++;
    }
    return bag;
}

tData gettData(nlohmann::json const &json) {
    auto tdata = tData(
            to_int(json["id"]),
            to_int(json["frame"]),
            to_string(json["type"]),
            getIgeData(json["data"]),
            to_int(json["cid"]),
            to_bool(json["successful"]),
            to_string(json["gameoverreason"]),
            getReplay(json["replay"]),
            getSource(json["source"]),
            getOptions(json["options"]),
            getStats(json["stats"]),
            to_int(json["diyusi"]),
            getEnemy(json["enemies"]),
            getTarget(json["targets"]),
            to_int(json["fire"]),
            getBoardV(json["board"]),
            getBag(json["bag"]),
            getHold(json["hold"]),
            to_double(json["g"]),
            getControlling(json["controlling"]),
            getFalling(json["falling"]),
            getHandling(json["handling"]),
            to_bool(json["playing"])
            );

    return tdata;
}

Killer getKiller(nlohmann::json const &json) {
    auto killer = Killer(
            to_string(json["gameid"]),
            to_string(json["name"]),
            to_string(json["type"])
            );
    return killer;
}

Aggregatestats getAggregatestats(nlohmann::json const &json) {
    auto aggregatestats = Aggregatestats(
            to_double(json["apm"]),
            to_double(json["ppm"]),
            to_double(json["vsscore"])
            );
    return aggregatestats;
}

std::vector<Board> getBoard(nlohmann::json const &fulljson) {
    auto board = std::vector<Board>();
    nlohmann::json json;
    int i = 0;
    while (i < fulljson.size()) {
        json = fulljson[i];
        board.push_back(
                Board(to_string(json["id"]),
                to_string(json["username"]),
                to_bool(json["active"]),
                to_bool(json["success"]))
                );
        i++;
    }
    return board;
}

nlohmann::json parseJson(std::string const &path) {
    std::ifstream file(path);

    nlohmann::json json = nlohmann::json::parse(file);

    return json;
}

std::vector<Player> getEndcontext(nlohmann::json const &fulljson) {
    auto endcontext = std::vector<Player>();
    nlohmann::json json;
    int i = 0;

    while (i < fulljson.size()) {
        json = fulljson[i];
        endcontext.push_back(
                Player(to_string(json["id"]),
                to_string(json["username"]),
                getHandling(json["handling"]),
                to_bool(json["active"]),
                to_bool(json["success"]),
                to_int(json["inputs"]),
                to_int(json["pieceplaced"]),
                to_int(json["naturalorder"]),
                to_int(json["score"]),
                to_int(json["wins"]),
                getPoints(json["points"]),
                getAvgTracking(json["secondaryAvgTracking"]),
                getAvgTracking(json["tertiaryAvgTracking"]),
                getAvgTracking(json["extraAvgTracking"]))
                );
        i++;
    }

    return endcontext;
}

std::vector<tEvent> getEvents(nlohmann::json const &fulljson) {
    auto events = std::vector<tEvent>();
    nlohmann::json json;
    int i = 0;
    while (i < fulljson.size()) {
        json = fulljson[i];
        events.push_back(
                tEvent(to_int(json["frame"]),
                to_string(json["type"]),
                gettData(json["data"]),
                getKiller(json["killer"]),
                getAggregatestats(json["aggregatestats"]))
                );
        i++;
    }
    return events;
}

std::vector<Data> getData(nlohmann::json const &fulljson) {
    auto data = std::vector<Data>();
    nlohmann::json json;
    int i = 0;
    while (i < fulljson.size()) {
        json = fulljson[i];
        data.push_back(
                Data(getBoard(json["board"]),
                to_int(json["frames"]),
                getEvents(json["events"]))
                );
        i++;
    }
    return data;
}

Ttr parseTtr(std::string const &path) {
    auto json = parseJson(path);
    auto ttr = Ttr();

    ttr._id = to_string(json["_id"]);
    ttr.endcontext = getEndcontext(json["endcontext"]);
    ttr.gametype = to_string(json["gametype"]);
    ttr.ismulti = to_bool(json["isMulti"]);
    ttr.mt = to_long(json["mt"]);
    ttr.shortid = to_string(json["shortid"]);
    ttr.ts = to_string(json["ts"]);
    ttr.verified = to_bool(json["verified"]);
    ttr.data = getData(json["data"]);
    ttr.back = to_string(json["back"]);
    ttr.forcestyle = to_string(json["forcestyle"]);

    return ttr;
}


