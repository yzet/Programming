int main(){
    #define NUMBER 405

    int inverted_number = 0;

    inverted_number += NUMBER % 10 * 100 + NUMBER % 100 / 10 * 10 + NUMBER / 100 * 1;

    return 0;
}