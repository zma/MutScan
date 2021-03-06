#include "match.h"
#include <vector>

Match::Match(Read* r, int pos, int distance, bool reversed){
    mRead = new Read(*r);
    mDistance = distance;
    mPos = pos;
    mReversed = reversed;
}

Match::~Match(){
    delete mRead;
}

void Match::print(int leftlen, int centerlen, int rightlen){
    cout<<"pos: "<<mPos<<", distance: "<<mDistance;
    if(mReversed)
        cout<<", reverse";
    else
        cout<<", forward";
    cout<<endl;
    vector<int> breaks;
    breaks.push_back(mPos);
    breaks.push_back( mPos+leftlen );
    breaks.push_back( mPos+leftlen+centerlen );
    breaks.push_back( mPos+leftlen+centerlen+rightlen);
    mRead->printWithBreaks(breaks);
}

void Match::printHtmlTD(ofstream& file, int leftlen, int centerlen, int rightlen){
    file<<"<a title='"<<mRead->mName<<"'>";
    file<<"d:" << mDistance;
    if(mReversed)
        file<<", <--";
    else
        file<<", -->";

    file<<"</a></span>";

    vector<int> breaks;
    breaks.push_back(mPos);
    breaks.push_back( mPos+leftlen );
    breaks.push_back( mPos+leftlen+centerlen );
    breaks.push_back( mPos+leftlen+centerlen+rightlen);
    mRead->printHtmlTDWithBreaks(file, breaks);
}

void Match::setReversed(bool flag){
    mReversed = flag;
}