
char* video_memory = (char*) 0xb8000;// global variable that points to the video memory address
int counter_postion = 0;

void print(const char* message);
extern "C" void kmain (){
    print("Hello, World!");

}

void print(const char* message) {

    for(int i = 0; message[i] !='\0';i++ ){
        

        if (message[i] == '\n') {
        // update counter_postion here
        counter_postion = (counter_postion / 80 + 1) * 80;
         

         } 
        else {
        // your existing two lines — write character and color
        video_memory[(counter_postion)*2] = message[i];
        video_memory[(counter_postion)*2 + 1] = 0x0F;
        counter_postion++;
        }
    }



}