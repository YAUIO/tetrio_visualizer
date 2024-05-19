#pragma once

#include <string>
#include <vector>

class Handling {
    int arr;
    int das;
    int dcd;
    int sdf;
    bool safelock;
    bool cancel;
    bool may20g;
};

class PointsExtra {
public:
    std::string vs;
};

class AvgTracking {
    std::vector<double> arr;
    std::string extraName;
};

class Points {
    int primary;
    double secondary;
    double tertiary;
    PointsExtra extra;
};

class Player {
public:
    std::string id;
    std::string username;
    Handling handling;
    bool active;
    bool success;
    int inputs;
    int pieceplaced;
    int nauralorder;
    int score;
    int wins;
    Points points;
    AvgTracking secondaryAvgTracking;
    AvgTracking tertiaryAvgTracking;
    AvgTracking extraAvgTracking;
};

class Board {
public:
    std::string id;
    std::string username;
    bool active;
    bool success;
};

class Replay {
public:

};

class Source {
public:

};

class Objective {
public:
    std::string type;
};

class Constants_overrides {
public:

};

class Minoskin {
public:
    std::string z;
    std::string l;
    std::string o;
    std::string s;
    std::string i;
    std::string j;
    std::string t;
    std::string other;
};

class Options {
public:
    int version;
    bool seed_random;
    double g;
    bool countdown;
    int countdown_count;
    int countdown_interval;
    int precountdown;
    int prestart;
    std::string mission;
    std::string mission_type;
    std::string zoominto;
    std::string slot_counter1;
    std::string slot_counter2;
    std::string slot_counter3;
    std::string slot_counter5;
    std::string slot_bar1;
    bool display_fire;
    bool display_username;
    bool hasgarbage;
    bool bgmnoreset;
    bool neverstopbgm;
    bool display_next;
    bool display_hold;
    bool infinite_hold;
    int gmargin;
    double gincrease;
    int garbagecap;
    int garbagecapincrease;
    int garbagecapmax;
    bool garbageabsolutecap;
    int garbageholesize;
    bool garbagephase;
    bool garbagequeue;
    int garbageare;
    std::string garbageentry;
    std::string garbageblocking;
    std::string garbagetargetbonus;
    std::string presets;
    std::string bagtype;
    std::string spinbonuses;
    std::string combotable;
    std::string kickset;
    int nextcount;
    bool allow_harddrop;
    bool display_shadow;
    int locktime;
    int garbagespeed;
    int forfeit_time;
    int are;
    int lineclear_are;
    bool infinitemovement;
    int lockresets;
    bool allow180;
    Objective objective;
    bool room_handling;
    int room_handling_arr;
    int room_handling_das;
    int room_handling_sdf;
    bool manual_allowed;
    bool b2bchaining;
    bool allclears;
    bool clutch;
    bool nolockout;
    std::string passthrough;
    bool can_undo;
    bool can_retry;
    bool retryisclear;
    bool noextrawidth;
    bool stride;
    int boardwidth;
    int boardheight;
    bool new_payback;
    int messiness_change;
    int messiness_inner;
    bool messiness_nosame;
    int messiness_timeout;
    bool usebombs;
    std::string song;
    std::string latencypreference;
    Handling handling;
    int fulloffset;
    int fullinterval;
    std::string gameid;
    std::string username;
    Constants_overrides constantsoverrides;
    bool gravitymax20g;
    bool garbageattackcap;
    bool nosound;
    bool shielded;
    int boardbuffer;
    int survival_cap;
    int survival_timer_itv;
    int survival_layer_min;
    Minoskin minoskin;
    std::string ghostskin;
    std::string boardskin;
};

class Time {
    int start;
    bool zero;
    bool locked;
    int prev;
    int framoffset;
};

class Clears {
    int singles;
    int doubles;
    int triples;
    int quads;
    int pentas;
    int realtspins;
    int minitspins;
    int minitspinsingles;
    int tspinsingles;
    int minitspindoubles;
    int tspindoubles;
    int tspintriples;
    int tspinquads;
    int tspinpentas;
    int allclear;
};

class Stats {
    long seed;
    int lines;
    int level_lines;
    int level_lines_needed;
    int inputs;
    int holds;
    Time time;
    int score;
    int zenlevel;
    int zenprogress;
    int level;
    int combo;
    int btb;
    int topbtb;
    int currentbtbchainpower;
    int tspins;
    int piecesplaced;

};

class tData {
public:
    bool successful;
    std::string gameoverreason;
    Replay replay;
    Source source;
    Options options;
};

class tEvent {
public:
    int frame;
    std::string type;
    tData data;
};

class Data {
public:
    std::vector<Board> board;
    int frames;
    std::vector<tEvent> events;
};

class Ttr {
public:
    std::string _id;
    std::vector<Player> endcontext;
    std::string gametype;
    bool ismulti;
    long mt;
    std::string shortid;
    std::string ts;
    bool verified;
    std::vector<Data> data;
};
