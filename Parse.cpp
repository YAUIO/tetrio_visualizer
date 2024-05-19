#include "Parse.h"

bool to_bool(nlohmann::json const& json){
    std::string jsonstr = to_string(json);
    if(jsonstr == "true"){
        return true;
    }else{
        return false;
    }
}

long to_long(nlohmann::json const& json){
    std::string jsonstr = to_string(json);
    try{
        return std::stol(jsonstr);
    }catch (std::invalid_argument & e){
        return 0;
    }
}

int to_int(nlohmann::json const& json){
    std::string jsonstr = to_string(json);
    try{
        return std::stoi(jsonstr);
    }catch (std::invalid_argument & e){
        return 0;
    }
}

double to_double(nlohmann::json const& json){
    std::string jsonstr = to_string(json);
    try{
        return std::stod(jsonstr);
    }catch (std::invalid_argument & e){
        return 0;
    }
}

Handling getHandling(nlohmann::json const& json){
    auto handling = Handling(to_int(json["arr"]),
                             to_int(json["das"]),
                             to_int(json["dcd"]),
                             to_int(json["sdf"]),
                             to_bool(json["safelock"]),
                             to_bool(json["cancel"]),
                             to_bool(json["may20g"]));
    return handling;
}

Points getPoints(nlohmann::json const& json){
    auto points = Points();

    return points;
}

AvgTracking getAvgTracking(nlohmann::json const& json){
    auto avgtracking = AvgTracking();

    return avgtracking;
}

igeData getIgeData(nlohmann::json const& json){
    auto igedata = igeData();

    return igedata;
}

Replay getReplay(nlohmann::json const& json){
    auto replay = Replay();

    return replay;
}

Source getSource(nlohmann::json const& json){
    auto source = Source();

    return source;
}

Options getOptions(nlohmann::json const& json){
    auto options = Options();

    return options;
}

Stats getStats(nlohmann::json const& json){
    auto stats = Stats();

    return stats;
}

Hold getHold(nlohmann::json const& json){
    auto hold = Hold();

    return hold;
}

Controlling getControlling(nlohmann::json const& json){
    auto controlling = Controlling();

    return controlling;
}

Falling getFalling(nlohmann::json const& json){
    auto falling = Falling();

    return falling;
}

std::vector<Enemy> getEnemy(nlohmann::json const& json){
    auto enemy = std::vector<Enemy>();

    return enemy;
}

std::vector<Target> getTarget(nlohmann::json const& json){
    auto target = std::vector<Target>();

    return target;
}

std::vector<BoardV> getBoardV(nlohmann::json const& json){
    auto boardV = std::vector<BoardV>();

    return boardV;
}

std::vector<std::string> getBag(nlohmann::json const& json){
    auto bag = std::vector<std::string>();

    return bag;
}

tData gettData(nlohmann::json const& json){
    auto tdata = tData(to_int(json["id"]),
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
                       to_bool(json["playing"]));

    return tdata;
}

Killer getKiller(nlohmann::json const& json){
    auto killer = Killer(to_string(json["gameid"]),
                         to_string(json["name"]),
                         to_string(json["type"]));
    return killer;
}

Aggregatestats getAggregatestats(nlohmann::json const& json){
    auto aggregatestats = Aggregatestats(to_double(json["apm"]),
                                         to_double(json["ppm"]),
                                         to_double(json["vsscore"]));
    return aggregatestats;
}

std::vector<Board> getBoard(nlohmann::json const& fulljson){
    auto board = std::vector<Board>();
    nlohmann::json json;
    int i = 0;
    while(i<fulljson.size()){
        json = fulljson[i];
        board.push_back(Board(to_string(json["id"]),
                              to_string(json["username"]),
                              to_bool(json["active"]),
                              to_bool(json["success"])));
        i++;
    }
    return board;
}

nlohmann::json parseJson(std::string const& path){
    std::ifstream file(path);

    nlohmann::json json = nlohmann::json::parse(file);

    return json;
}

std::vector<Player> getEndcontext(nlohmann::json const& fulljson){
    auto endcontext = std::vector<Player>();
    nlohmann::json json;
    int i = 0;

    while (i<fulljson.size()){
        json = fulljson[i];
        endcontext.push_back(Player(to_string(json["id"]),
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
                                    getAvgTracking(json["extraAvgTracking"])));
        i++;
    }

    return endcontext;
}

std::vector<tEvent> getEvents(nlohmann::json const& fulljson){
    auto events = std::vector<tEvent>();
    nlohmann::json json;
    int i = 0;
    while(i<fulljson.size()){
        json = fulljson[i];
        events.push_back(tEvent(to_int(json["frame"]),
                                to_string(json["type"]),
                                gettData(json["data"]),
                                getKiller(json["killer"]),
                                getAggregatestats(json["aggregatestats"])));
        i++;
    }
    return events;
}

std::vector<Data> getData(nlohmann::json const& fulljson){
    auto data = std::vector<Data>();
    nlohmann::json json;
    int i = 0;
    while(i<fulljson.size()){
        json = fulljson[i];
        data.push_back(Data(getBoard(json["board"]),
                            to_int(json["frames"]),
                            getEvents(json["events"])));
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


