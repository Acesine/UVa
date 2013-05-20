#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define cin datafile

void str2Int(string str,int *result)
{
    *result = 0;
    for(int i=0; i<str.length(); i++)
    {
        *result = (*result)*10 + (str[i]-'0');
    }
}
string lowerCase(string str)
{
    string result;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            result.push_back('a'+str[i]-'A');
        }
        else
        {
            result.push_back(str[i]);
        }
    }
    return result;
}

class TeamInfo
{
public:
    string name;
    int points_earned;
    int wins;
    int ties;
    int losses;
    int goals_scored;
    int goals_against;
    bool operator<(const TeamInfo& other) const;
    void printTeamInfo();
};

bool TeamInfo::operator<(const TeamInfo& other) const
{
    if(this->points_earned > other.points_earned)
        return true;
    if(this->points_earned < other.points_earned)
        return false;
    if(this->wins > other.wins)
        return true;
    if(this->wins < other.wins)
        return false;
    if((this->goals_scored-this->goals_against) > (other.goals_scored-other.goals_against))
        return true;
    if((this->goals_scored-this->goals_against) < (other.goals_scored-other.goals_against))
        return false;
    if(this->goals_scored > other.goals_scored)
        return true;
    if(this->goals_scored < other.goals_scored)
        return false;
    if((this->wins+this->ties+this->losses) < ((other.wins+other.ties+other.losses)))
        return true;
    if((this->wins+this->ties+this->losses) > ((other.wins+other.ties+other.losses)))
        return false;
    string str1 = lowerCase(this->name);
    string str2 = lowerCase(other.name);
    if(str1.compare(str2)<0)
        return true;
    else
        return false;
}
void TeamInfo::printTeamInfo()
{
    cout<<this->name<<" ";
    cout<<this->points_earned<<"p, ";
    cout<<(this->wins+this->losses+this->ties)<<"g (";
    cout<<this->wins<<"-"<<this->ties<<"-"<<this->losses<<"), ";
    cout<<(this->goals_scored-this->goals_against)<<"gd (";
    cout<<this->goals_scored<<"-"<<this->goals_against<<")"<<endl;
}

class TournamentInfo
{
public:
    string name;
    int numOfTeams;
    vector<TeamInfo> teams;

    void Init(int T,string str);
    void setTeam(string teamname);
    void setInfo(string gameinfo);
    int findTeam(string teamname);
    void sortInfo();
    void printInfo();
};

void TournamentInfo::Init(int T,string str)
{
    this->name = str;
    this->numOfTeams = T;
}
void TournamentInfo::setTeam(string teamname)
{
    TeamInfo tmp;
    tmp.name = teamname;
    tmp.points_earned = 0;
    tmp.wins = 0;
    tmp.ties = 0;
    tmp.losses = 0;
    tmp.goals_scored = 0;
    tmp.goals_against = 0;
    this->teams.push_back(tmp);
}
void TournamentInfo::setInfo(string gameinfo)
{
    string team1="",team2="",s1,s2;
    int score1,score2;
    int count = 0;
    while(gameinfo[count] != '#')
    {
        team1.push_back(gameinfo[count]);
        count ++;
    }
    count++;
    while(gameinfo[count] != '@')
    {
        s1.push_back(gameinfo[count]);
        count ++;
    }
    count++;
    while(gameinfo[count] != '#')
    {
        s2.push_back(gameinfo[count]);
        count ++;
    }
    count++;
    while(count < gameinfo.length())
    {
        team2.push_back(gameinfo[count]);
        count ++;
    }
    str2Int(s1,&score1);
    str2Int(s2,&score2);
    //update info
    int tmnum1 = this->findTeam(team1);
    int tmnum2 = this->findTeam(team2);
    if(tmnum1 == -1 || tmnum2 == -1)
        return;
    this->teams[tmnum1].goals_against += score2;
    this->teams[tmnum1].goals_scored += score1;
    this->teams[tmnum2].goals_against += score1;
    this->teams[tmnum2].goals_scored += score2;
    if(score1>score2)
    {
        this->teams[tmnum1].wins ++;
        this->teams[tmnum1].points_earned += 3;
        this->teams[tmnum2].losses ++;
    }
    else
    {
        if(score1 == score2)
        {
            this->teams[tmnum1].ties ++;
            this->teams[tmnum1].points_earned += 1;
            this->teams[tmnum2].ties ++;
            this->teams[tmnum2].points_earned += 1;
        }
        else
        {
            this->teams[tmnum1].losses ++;
            this->teams[tmnum2].wins ++;
            this->teams[tmnum2].points_earned += 3;
        }
    }
}
int TournamentInfo::findTeam(string teamname)
{
    for(int i=0; i<numOfTeams; i++)
    {
        if(teams[i].name.compare(teamname) == 0)
            return i;
    }
    return -1;
}
void TournamentInfo::sortInfo()
{
    sort(teams.begin(),teams.end());
}
void TournamentInfo::printInfo()
{
    this->sortInfo();
    cout<<this->name<<endl;
    for(int i=0; i<this->numOfTeams; i++)
    {
        cout<<i+1<<") ";
        this->teams[i].printTeamInfo();
    }
}

int main()
{
    ifstream datafile("data");
    int N;
    cin>>N;
    cin.get();
    while(N--)
    {
        TournamentInfo tournament;
        string tourname;
        int T;
        int G;
        getline(cin,tourname);
        cin>>T;
        //init tornament
        tournament.Init(T,tourname);
        //init teams
        cin.get();
        for(int i=0; i<T; i++)
        {
            string teamname_temp;
            getline(cin,teamname_temp);
            tournament.setTeam(teamname_temp);
        }
        //init info
        cin>>G;
        cin.get();
        for(int i=0; i<G; i++)
        {
            string gameinfo;
            getline(cin,gameinfo);
            tournament.setInfo(gameinfo);
        }
        //print
        tournament.printInfo();
        cout<<endl;
    }
    return 0;
}
