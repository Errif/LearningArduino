// Declare global constants
const boolean likeApples = true;
const boolean likeBananas = true;
const boolean likeRasins = true;

void setup(){

    // Open serial connection
    Serial.begin(9600);

}

void loop(){

    Serial.println("## Determining your preferences ## \n");

    if(likeApples == true && likeBananas == false){
        Serial.println("Have an apple!");
    }
    else if (likeApples == false && likeBananas == true) {
        Serial.println("Have a banana!");
    }
    else if (likeApples == true && likeBananas == true) {

        if(likeRasins == true){
        Serial.println("Have some fruit salad with rasins");
        }
        else {
            Serial.println("Have som fruit salad without rasins!");
        }

    }
    else{
        Serial.println("You don't like fruit, right?");
    }

    delay(1000);

}