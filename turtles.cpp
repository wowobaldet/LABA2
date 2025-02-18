#include "Func.h"

void TrueOrFalse(int kol){
Set ht(kol);
    int begins, ends;
    for(int i=0; i< kol; i++){
        cin>>begins>>ends;
        if(begins+ends==(kol-1)){
            ht.SetPush(to_string(begins));
        }
    }
    int maxs=0;
    for(int i=0; i < kol; i++){
        if(ht.setik[i]!= nullptr){
            maxs++;
        }
    }
    cout<<maxs<<endl;
}