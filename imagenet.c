/*
 ******************************************************************
 * HISTORY
 * 15-Oct-94  Jeff Shufelt (js), Carnegie Mellon University
 *      Prepared for 15-681, Fall 1994.
 *
 ******************************************************************
 */

#include <stdio.h>
#include <pgmimage.h>
#include <backprop.h>

extern void exit();

#define TARGET_HIGH 0.9
#define TARGET_LOW 0.1
void checkPose(BPNN * net, char head[]);
void checkSunnies(BPNN *net, char eyes[]);

/*** This is the target output encoding for a network with one output unit.
     It scans the image name, and if it's an image of me (js) then
     it sets the target unit to HIGH; otherwise it sets it to LOW.
     Remember, units are indexed starting at 1, so target unit 1
     is the one to change....  ***/

load_target(img, net)
IMAGE *img;
BPNN *net;
{
  int scale;
  char userid[40], head[40], expression[40], eyes[40], photo[40];

  userid[0] = head[0] = expression[0] = eyes[0] = photo[0] = '\0';

  /*** scan in the image features ***/
  sscanf(NAME(img), "%[^_]_%[^_]_%[^_]_%[^_]_%d.%[^_]",
    userid, head, expression, eyes, &scale, photo);
//    printf("pose: %s %f %f %f\n\n", head, net->target[3], net->target[2], net->target[1]);
  if(!strcmp(userid,"an2i")){
      // 00000
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"at33")){
      // 00001
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"boland")){
      // 00010
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"bpm")){
      //00011
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"ch4f")){
      // 00100
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_HIGH;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"cheyer")){
      // 00101
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_HIGH;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"choon")){
      // 00110
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_HIGH;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_LOW;

  }else if(!strcmp(userid,"danieln")){
      // 00111
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_HIGH;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"glickman")){
    //01000
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_HIGH;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"karyadi")){
      // 01001
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_HIGH;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"kawamura")){
      // 01010
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_HIGH;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"kk49")){
      // 01011
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_HIGH;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"megak")){
      // 01100
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_HIGH;
      net->target[4] = TARGET_HIGH;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"mitchell")){
      // 01101
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_HIGH;
      net->target[4] = TARGET_HIGH;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"night")){
      // 01110
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_HIGH;
      net->target[4] = TARGET_HIGH;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"phoebe")){
      // 01111
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_HIGH;
      net->target[4] = TARGET_HIGH;
      net->target[5] = TARGET_LOW;
  }else if(!strcmp(userid,"saavik")){
      // 10000
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_HIGH;
  }else if(!strcmp(userid,"steffi")){
      // 10001
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_LOW;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_HIGH;
  }else if(!strcmp(userid,"s224")){
      // 10010
      net->target[1] = TARGET_LOW;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_HIGH;
  }else if(!strcmp(userid,"tanmo")){
      // 10011
      net->target[1] = TARGET_HIGH;
      net->target[2] = TARGET_HIGH;
      net->target[3] = TARGET_LOW;
      net->target[4] = TARGET_LOW;
      net->target[5] = TARGET_HIGH;
  }
    checkPose(net, head);
    checkSunnies(net,eyes);
//      printf(" %s  %s  %s %f %f %f %f %f %f %f %f %f\n\n", eyes,head,userid, net->target[9] ,net->target[8], net->target[7],net->target[6], net->target[5], net->target[4],net->target[3], net->target[2], net->target[1]);
}

  void checkPose(BPNN * net, char head[]){
      if(!strcmp(head,"up")){
          //000
          net->target[6] = TARGET_LOW;
          net->target[7] = TARGET_LOW;
          net->target[8] = TARGET_LOW;
      }else if(!strcmp(head,"right")){
          //001
          net->target[6] = TARGET_HIGH;
          net->target[7] = TARGET_LOW;
          net->target[8] = TARGET_LOW;
      }else if(!strcmp(head,"left")){
          //010
        net->target[6] = TARGET_LOW;
        net->target[7] = TARGET_HIGH;
        net->target[8] = TARGET_LOW;
      }else if(!strcmp(head,"straight")){
          //100
        net->target[6] = TARGET_LOW;
        net->target[7] = TARGET_LOW;
        net->target[8] = TARGET_HIGH;
      }

  }

  void checkSunnies(BPNN *net, char eyes[]){
      if(!strcmp(eyes,"sunglasses")){
          net->target[9] = TARGET_HIGH;
      }else{
          net->target[9] = TARGET_LOW;
      }
  }

/***********************************************************************/
/********* You shouldn't need to change any of the code below.   *******/
/***********************************************************************/

load_input_with_image(img, net)
IMAGE *img;
BPNN *net;
{
  double *units;
  int nr, nc, imgsize, i, j, k;

  nr = ROWS(img);
  nc = COLS(img);
  imgsize = nr * nc;;
  if (imgsize != net->input_n) {
    printf("LOAD_INPUT_WITH_IMAGE: This image has %d pixels,\n", imgsize);
    printf("   but your net has %d input units.  I give up.\n", net->input_n);
    exit (-1);
  }

  units = net->input_units;
  k = 1;
  for (i = 0; i < nr; i++) {
    for (j = 0; j < nc; j++) {
      units[k] = ((double) img_getpixel(img, i, j)) / 255.0;
      k++;
    }
  }
}
