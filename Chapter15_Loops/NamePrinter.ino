/* // Define global name array
const String names[] = {"Alice", "Bob", "Charlie", "Dave"};

void setup(){
    // Open serial connection at 9600 Bd
    Serial.begin(9600);
}

void loop(){
	
    // Print all names in names[] array
    for(int i = 0; i <= 3; i++){
        Serial.println(names[i]);
    }
    
    // Print all names in names[] array in reverse order
    for(int i = 3; i >= 0; i--){
        Serial.println(names[i]);
    }
    

    Serial.println("--------");

    // Halt execution for specified number of milliseconds
    delay(1000);
}
 */