

unsigned int selectedFruitCount[9];

void setup(){

    // Open serial connection
    Serial.begin(9600);

}

void loop(){

    // Get (pseudo)random value between 0 and 9
    byte value = random(0,9);

    String pickedFruit;

    switch (value)
    {           
        case 0:
            pickedFruit = "banana";
            break;
        case 1:
            pickedFruit = "clementine";
            break;
        case 2:
            pickedFruit = "grape";
            break;
        case 3:
            pickedFruit = "mango";
            break;
        case 4:
            pickedFruit = "pear";
            break;
        default:
            pickedFruit = "pineapple";
            break;
    }

    Serial.print("Have a ");
    Serial.println(pickedFruit);
    Serial.print("\n");

    // Add fruit to count
    selectedFruitCount[value] += 1;

    for (int i = 0; i < 9; i++){
        Serial.print(" ");
        Serial.print(i);
        Serial.print(": ");
        for(int c = 0; c <= selectedFruitCount[i]; c++){
            Serial.print("|");
        }
        Serial.print("\n");
    }

    Serial.print("\n");

    delay(1000);
}