class Solution {
public:
    int findDayofYear(string date,vector<int>&cumMonthDays){
        int month=stoi(date.substr(0,2));
        int days=stoi(date.substr(3));
        return cumMonthDays[month-1]+days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>monthdays={31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int>cumMonthDays(13,0);
        cumMonthDays[1]=31;
        for(int i=2;i<=12;i++){
            cumMonthDays[i]=cumMonthDays[i-1]+monthdays[i-1];
        }
        int arriveAliceDay=findDayofYear(arriveAlice,cumMonthDays);
        int leaveAliceDay=findDayofYear(leaveAlice,cumMonthDays);
        int arriveBobDay=findDayofYear(arriveBob,cumMonthDays);
        int leaveBobDay=findDayofYear(leaveBob,cumMonthDays);
        int overLapDays=min(leaveAliceDay,leaveBobDay)-max(arriveAliceDay,arriveBobDay)+1;
        return overLapDays<0?0:overLapDays;

    }
};