int main(){
    #define x -2.0
    
    double y = 0.0f;

    if (x < -1){
         y = -1 / x;
    } 
    else if (x < 1){
         y = x * x;
    }  
    else{
        y = 1; 
    }  
    return 0;
}