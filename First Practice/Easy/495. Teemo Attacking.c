// Solution 1
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    if(duration == 0){
        return 0;
    }
    int sum = 0; // 中毒合計時間
    for(int i = 0; i < timeSeriesSize - 1; i++){
        if(timeSeries[i] + duration <= timeSeries[i+1]){
            sum += duration;
        }
        else{
            sum += (timeSeries[i+1] - timeSeries[i]);
        }
    }
    return sum + duration;
}