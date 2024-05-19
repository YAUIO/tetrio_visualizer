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

Handling getHandling(nlohmann::json const& json){
    auto handling = Handling();

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

Board getBoard(nlohmann::json const& json){
    auto board = Board();

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

std::vector<Data> getData(nlohmann::json const& fulljson){
    auto data = std::vector<Data>();
    nlohmann::json json;
    int i = 0;
    while(i<fulljson.size()){
        json = fulljson[i];
        data.push_back(Data(getBoard(json),
                            ))

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


