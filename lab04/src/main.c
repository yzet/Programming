int main(){
    // task 1
    // calculate perimetr, square or radius depending on the value of command
    #define PI 3.1415f
    #define RADIUS 4.0f
    #define COMMAND 'l'

    float result = 0;
    switch (COMMAND)
    {
    case 'l':
        result = 2.0f * PI * RADIUS; // perimetr
        break;
    case 's':
        result = PI * RADIUS * RADIUS; // square
        break;
    case 'v':
        result = (4.0f / 3.0f) * RADIUS * RADIUS * RADIUS * PI; // volume
        break;
    default:
        result = -1;
        break;
    }
    // end task 1
    // task 2
    // take difference of fractional and intenger parts
    #define NUMBER 123.655f

    int intenger_part_of_number = (int)NUMBER;
    double fractional_part_of_number = (NUMBER - intenger_part_of_number) * 1000.0;

    if (fractional_part_of_number == 0){ // check devider on zero
        return 0;
    }

    double difference = (fractional_part_of_number / intenger_part_of_number);
    difference = (int)(difference * 100) / 100.0; // trimming number
    // end task 2
    // task 3
    // set vars as k < m < n
    int k = 9;
    int m = 3;
    int n = 6;
    int buff = 0;

    if (!((m > k) && (m < n))) // if result ready on input parameters
    {
        if (k > m && k > n){
            buff = n;
            n = k;
            k = buff;
        } else if (m > n)
        {
            buff = n;
            n = m;
            m = buff;
        }
        if (k > m){
            buff = m;
            m = k;
            k = buff;
        }
    }
    // end task 3
    // task 4
    // determine the value of y depending on the value of x
    #define x_task_4 2.0
    
    double y_task_4 = 0.0f;

    if (x_task_4 < -1){
         y_task_4 = -1.0 / x_task_4; 
    } 
    else if (x_task_4 < 1){
         y_task_4 = x_task_4 * x_task_4;
    }  
    else{
        y_task_4 = 1; 
    }  
    // end task 4
    // task 5
    // determine the value of y depending on the value of x
    #define x_task_5 0.02
    
    double y_task_5 = 0.0;

    if(x_task_5 > -1 && x_task_5 <= 0){
       y_task_5 = x_task_5 + 1;
    } 
    else if (x_task_5 > 0 && x_task_5 < 1)
    {
        y_task_5 = -x_task_5 + 1;
    } 
    else if (x_task_5 < -1){
        y_task_5 = -x_task_5 - 1;
    } 
    else
    {
        y_task_5 = x_task_5 - 1;
    }
    // end task 5
    return 0;
}
