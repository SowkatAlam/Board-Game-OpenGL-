#include <GL/glut.h>

#include <bits/stdc++.h>
using namespace std;

/*  Initialize material property, light source, lighting model,
 *  and depth buffer.
 */

 #define board_siz_x 6
 #define board_siz_y 5

 double screen_x_min=-2.5;
 double screen_x_max=2.5;
 double screen_y_min=-1.5;
 double screen_y_max=1.5;
 double x_size=.66,y_size=.6;
 double board_ceil_x_values[board_siz_x][board_siz_y];
 double board_ceil_y_values[board_siz_x][board_siz_y];
 double translate_chokkha_x=0,translate_chokkha_y=0;


 void drawText(const char *text, int length,double x,double y);
  void drawText_1(const char *text, int length,double x,double y);
  void drawText_2(const char *text, int length,double x,double y);

void init(void);
void init_markar(void);
void draw_markar();
void init_markar_1();
void draw_player_information();
void init_snake_body_1();
void init_snake_body_2();
void init_snake_moutght();
void init_chokkha_base();






float _angle = 0.0;




int randdom(int nn)
{


    int xxx = rand();

    while (xxx >= RAND_MAX - (RAND_MAX % nn)) {
      xxx = rand();
    }

    xxx%=nn;
    return xxx;



}

void light_disable()
{
    glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glDisable(GL_DEPTH_TEST);
}
int cone_y=0;

bool rotate_x=true;
bool rotate_y=true;
void rotate_chokkha()
{
    if(rotate_x==true&&rotate_y==true)
    {

        glRotatef(_angle,1,1,0);
    }
    else if(rotate_x==true)
    {
        glRotatef(_angle,0,1,0);

    }
    else
    {
        glRotatef(_angle,1,0,0);
    }
}

void draw_board()
{
    double xx=screen_x_min,yy=screen_y_min;
    int color[4][3]={
        {
            1,1,0
        },
        {
            1,0,1
        },
        {
            0,1,0
        },
        {
            0,0,1
        }
    };
    int color_count=0;
    double xx_text=(x_size-.15)*100,yy_text=(y_size-.10)*100;
    std::string text;


    int inforstring[30]={1,2,3,4,5,6,12,11,10,9,8,7,13,14,15,16,17,18,24,23,22,21,20,19,25,26,27,28,29};

    int id=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            glColor3f(color[color_count][0],color[color_count][1],color[color_count][2]);

            color_count++;
            if(color_count>=4)
            {
                color_count=0;
            }

            glBegin(GL_QUADS);
            board_ceil_x_values[i][j]=xx;
            board_ceil_y_values[i][j]=yy;
            glVertex3f(xx,yy,0);
            glVertex3f(xx+x_size-.01,yy,0);
            glVertex3f(xx+x_size-.01,yy+y_size,0);
            glVertex3f(xx,yy+y_size,0);
            glEnd();
            xx+=x_size;

            glColor3f(.25,.30,.74);

            stringstream convert;


            if(id==29)
            {
                //convert<<"winner";
                //text=convert.str();
                //drawText(text.data(),text.size(),xx_text-5,yy_text);
                //xx_text+=(x_size+x_size-.27)*100;
            }
            else
            {
                convert<<inforstring[id++];
                text=convert.str();
                drawText(text.data(),text.size(),xx_text,yy_text);
                xx_text+=(x_size+x_size-.27)*100;
            }

        }

        xx=screen_x_min;
        yy+=y_size;
        xx_text=(x_size-.15)*100;
        yy_text+=(y_size+y_size)*100;
    }
}


void draw_chokkha();

void draw_lader()
{

    glPushMatrix();

    glTranslatef(.66+.66,.6+.6,0);


    // first slope
    glPushMatrix();

    glTranslatef(-.1,.05,0);

    glPushMatrix();
    init();
    glTranslatef(-2.5+.66+.15,-1.2,0);
    glRotatef(90,-1,0,0);
    glRotatef(30,0,1,0);
    glutSolidCone(.05,1.5,15,15);
    light_disable();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(.66+.1,.6+.6+.12,0);
    init();
    glTranslatef(-2.5+.66+.15,-1.2,0);
    glRotatef(90,1,0,0);
    glRotatef(30,0,-1,0);
    glutSolidCone(.05,1.5,15,15);
    light_disable();
    glPopMatrix();

    glPopMatrix();

    //   first slope ends


    // second slope
    glPushMatrix();

    glTranslatef(.35,-.18,0);

    glPushMatrix();
    init();
    glTranslatef(-2.5+.66+.15,-1.2,0);
    glRotatef(90,-1,0,0);
    glRotatef(30,0,1,0);
    glutSolidCone(.05,1.5,15,15);
    light_disable();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(.66+.1,.6+.6+.12,0);
    init();
    glTranslatef(-2.5+.66+.15,-1.2,0);
    glRotatef(90,1,0,0);
    glRotatef(30,0,-1,0);
    glutSolidCone(.05,1.5,15,15);
    light_disable();
    glPopMatrix();

    glPopMatrix();
    // second slope ends here



    glPushMatrix();

    glTranslatef(-2.5+.66+.15+.10,-.8,0);

    glPushMatrix();
    init();
    glRotatef(90,0,1,0);
    glRotatef(30,1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();


    glPushMatrix();
    //glTranslatef(.66+.1,.6+.6+.12,0);
    init();
    glTranslatef(1-.58,-.25,0);
    glRotatef(90,0,-1,0);
    glRotatef(30,-1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();

    glPopMatrix();



    // second slope subordinary
    glPushMatrix();

    glTranslatef(-2.5+.66+.43,-.50,0);

    glPushMatrix();
    init();
    glRotatef(90,0,1,0);
    glRotatef(30,1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();


    glPushMatrix();
    //glTranslatef(.66+.1,.6+.6+.12,0);
    init();
    glTranslatef(1-.58,-.25,0);
    glRotatef(90,0,-1,0);
    glRotatef(30,-1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();

    glPopMatrix();





    glPushMatrix();

    glTranslatef(-2.5+.66+.60,-.20,0);

    glPushMatrix();
    init();
    glRotatef(90,0,1,0);
    glRotatef(30,1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();


    glPushMatrix();
    //glTranslatef(.66+.1,.6+.6+.12,0);
    init();
    glTranslatef(1-.58,-.25,0);
    glRotatef(90,0,-1,0);
    glRotatef(30,-1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();







    glPushMatrix();

    glTranslatef(-.66,.6,0);


    // first slope
    glPushMatrix();

    glTranslatef(-.1,.05,0);

    glPushMatrix();
    init();
    glTranslatef(-2.5+.66+.15,-1.2,0);
    glRotatef(90,-1,0,0);
    glRotatef(30,0,1,0);
    glutSolidCone(.05,1.5,15,15);
    light_disable();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(.66+.1,.6+.6+.12,0);
    init();
    glTranslatef(-2.5+.66+.15,-1.2,0);
    glRotatef(90,1,0,0);
    glRotatef(30,0,-1,0);
    glutSolidCone(.05,1.5,15,15);
    light_disable();
    glPopMatrix();

    glPopMatrix();

    //   first slope ends


    // second slope
    glPushMatrix();

    glTranslatef(.35,-.18,0);

    glPushMatrix();
    init();
    glTranslatef(-2.5+.66+.15,-1.2,0);
    glRotatef(90,-1,0,0);
    glRotatef(30,0,1,0);
    glutSolidCone(.05,1.5,15,15);
    light_disable();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(.66+.1,.6+.6+.12,0);
    init();
    glTranslatef(-2.5+.66+.15,-1.2,0);
    glRotatef(90,1,0,0);
    glRotatef(30,0,-1,0);
    glutSolidCone(.05,1.5,15,15);
    light_disable();
    glPopMatrix();

    glPopMatrix();
    // second slope ends here



    glPushMatrix();

    glTranslatef(-2.5+.66+.15+.10,-.8,0);

    glPushMatrix();
    init();
    glRotatef(90,0,1,0);
    glRotatef(30,1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();


    glPushMatrix();
    //glTranslatef(.66+.1,.6+.6+.12,0);
    init();
    glTranslatef(1-.58,-.25,0);
    glRotatef(90,0,-1,0);
    glRotatef(30,-1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();

    glPopMatrix();



    // second slope subordinary
    glPushMatrix();

    glTranslatef(-2.5+.66+.43,-.50,0);

    glPushMatrix();
    init();
    glRotatef(90,0,1,0);
    glRotatef(30,1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();


    glPushMatrix();
    //glTranslatef(.66+.1,.6+.6+.12,0);
    init();
    glTranslatef(1-.58,-.25,0);
    glRotatef(90,0,-1,0);
    glRotatef(30,-1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();

    glPopMatrix();





    glPushMatrix();

    glTranslatef(-2.5+.66+.60,-.20,0);

    glPushMatrix();
    init();
    glRotatef(90,0,1,0);
    glRotatef(30,1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();


    glPushMatrix();
    //glTranslatef(.66+.1,.6+.6+.12,0);
    init();
    glTranslatef(1-.58,-.25,0);
    glRotatef(90,0,-1,0);
    glRotatef(30,-1,0,0);
    glutSolidCone(.05,.5,15,15);
    light_disable();
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();




}


double snake_rotate=2;

void draw_snake()
{


    // first snake
    glPushMatrix();


    glTranslatef(.6+.6+.02,.14,0);


    glPushMatrix();

    init_snake_moutght();

    //glTranslatef(-.01,-.05,0);

    glTranslatef(-.04,.02,0);
    glScalef(.015,.015,1);
    glRotatef(90,-1,0,0);
    glRotatef(45,0,-1,0);
    glColor3f(1,0,0);//Color it red

    glScalef(0.5,0.5,0.5);
    glutSolidSphere(11,20,20);



    // mought
    glColor3f(1,0,0);
    glTranslatef(0,0.0,6.0);
    glScalef(0.8,1.0,1.0);
    glutSolidCone(10,10,20,20);
    light_disable();
    glColor3f(1,1,0);
    glTranslatef(-4.0,10.0,0.0);
    glScalef(0.3,0.3,0.3);
    glutSolidSphere(10,20,20);
    glTranslatef(26.0,0.0,0.0);
    glutSolidSphere(10,20,20);
   // glPopMatrix();
    light_disable();
    glPopMatrix();





    double xxx=0;
    double yyy=0;

    glPushMatrix();
    glRotatef(20,0,0,-1);

    init_snake_body_1();
    glTranslatef(0,-.08,0);
    glutSolidSphere(.08,20,20);


    glPushMatrix();

    xxx=.05;
    yyy=-.05;

    double siz=.08;

    for(int i=1;i<=24;i++)
    {
        if(i%2==0)
        {
            init_snake_body_1();
        }
        else
        {
            init_snake_body_2();
        }
        glTranslatef(xxx,yyy,0);
        glutSolidSphere(.08,20,20);
        if(i<=12)
        {
            xxx-=.01;
        }
        else
        {
            xxx+=.01;
        }

        light_disable();
    }
    if(snake_rotate>=0)
    {
        glRotatef(30,0,1,0);
    }
    else
    {
        glRotatef(30,-1,-1,0);
    }
    glPushMatrix();

    double temp_x=0,temp_y=0;
    for(int i=1;i<=8;i++)
    {
        if(i%2==0)
        {
            init_snake_body_1();
        }
        else
        {
            init_snake_body_2();
        }
        glTranslatef(xxx,yyy,0);
        glTranslatef(temp_x,temp_y,0);
        glutSolidSphere(siz,20,20);
        siz-=.01;
        temp_x=-.005;
        temp_y+=.003;
    }

    glPopMatrix();

    light_disable();
    glPopMatrix();
    glPopMatrix();


    glPopMatrix();














    // second snake
    glPushMatrix();


    glTranslatef(-.66-.2,.14+.6,0);


    glPushMatrix();

    init_snake_moutght();

    //glTranslatef(-.01,-.05,0);

    glTranslatef(.047,.009,0);
    glScalef(.015,.015,1);
    glRotatef(90,-1,0,0);
    glRotatef(50,0,1,0);
    glColor3f(1,0,0);//Color it red

    glScalef(0.5,0.5,0.5);
    glutSolidSphere(11,20,20);



    // mought
    glColor3f(1,0,0);
    glTranslatef(0,0.0,6.0);
    glScalef(0.8,1.0,1.0);
    glutSolidCone(10,10,20,20);
    light_disable();
    glColor3f(1,0,0);
    glTranslatef(-4.0,10.0,0.0);
    glScalef(0.3,0.3,0.3);
    glutSolidSphere(10,20,20);
    glTranslatef(26.0,0.0,0.0);
    glutSolidSphere(10,20,20);
   // glPopMatrix();
    light_disable();
    glPopMatrix();





     xxx=0;
     yyy=0;

    glPushMatrix();
    glRotatef(20,0,0,-1);

    init_snake_body_1();
    glTranslatef(0,-.08,0);
    glutSolidSphere(.08,20,20);


    glPushMatrix();

    xxx=-.05;
    yyy=-.05;

     siz=.08;

    for(int i=1;i<=24;i++)
    {
        if(i%2==0)
        {
            init_snake_body_1();
        }
        else
        {
            init_snake_body_2();
        }
        glTranslatef(xxx,yyy,0);
        glutSolidSphere(.08,20,20);
        if(i<=12)
        {
            xxx+=.01;
        }
        else
        {
            xxx-=.01;
        }

        light_disable();
    }
    if(snake_rotate>=0)
    {
        glRotatef(30,0,1,0);
    }
    else
    {
        glRotatef(30,-1,-1,0);
    }
    glPushMatrix();
    temp_x=0;
    temp_y=0;
    for(int i=1;i<=6;i++)
    {
        if(i%2==0)
        {
            init_snake_body_1();
        }
        else
        {
            init_snake_body_2();
        }
        glTranslatef(xxx,yyy,0);
        glTranslatef(temp_x,temp_y,0);
        glutSolidSphere(siz,20,20);
        siz-=.01;
        temp_x=+.005;
        temp_y+=.0005;
    }


    temp_x=0;
    temp_y=0;
    for(int i=1;i<=3;i++)
    {
        if(i%2==0)
        {
            init_snake_body_1();
        }
        else
        {
            init_snake_body_2();
        }
        temp_x=+.02;
        temp_y+=.01;
        glTranslatef(xxx,yyy,0);
        glTranslatef(temp_x,temp_y,0);
        glutSolidSphere(siz,20,20);
        siz-=.01;

    }

    glPopMatrix();

    light_disable();
    glPopMatrix();
    glPopMatrix();


    glPopMatrix();
}


void draw_chokkha_base()
{
    glPushMatrix();
    init_chokkha_base();
    glTranslatef(1.97,-1.74,0);
    glRotatef(90,1,0,0);
    glutSolidTorus(.3,.2,20,20);
    light_disable();
    glPopMatrix();
}


void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



   // player information

   // ------------------------player information ends here



   // drawing board
   glPushMatrix();
   draw_board();
   glPopMatrix();
   //----------------------  drawing board ends here


   //  cone identity code
   glPushMatrix();
   draw_markar();
   glPopMatrix();
   //----------------------drawing cone ends here

   // chokkha code
   glPushMatrix();
   glTranslatef(2,-1+translate_chokkha_y,0);
   glScalef(.90,.90,.90);
   draw_chokkha();
   glPopMatrix();
   //----------------------drawing chokkha ends here


   glPushMatrix();
   glPopMatrix();


   // lader code
   glPushMatrix();
   draw_lader();
   glPopMatrix();
   //---------------------drawing lader ends here


   // draw snake
   glPushMatrix();
   draw_snake();
   glPopMatrix();

   glPushMatrix();
   draw_player_information();
   glPopMatrix();

   glPushMatrix();
   draw_chokkha_base();
   glPopMatrix();
   glFlush ();
}








bool player_key_pressed=false;

int player_1_current=1,player_2_current=1;
bool player=true,player_2=false;

//double markar_xx[31]={0,0,.66,.66+.66,.66+.66+.66,.66+.66+.66+.66, (6)  .66+.66+.66+.66+.66, (7)  .66+.66+.66+.66+.66 , (8).66+.66+.66+.66, (9).66+.66+.66,  (10).66+.66,(11).66,0};
double markar_xx[31]={0,0,.66,.66+.66,.66+.66+.66,.66+.66+.66+.66,   .66+.66+.66+.66+.66,   .66+.66+.66+.66+.66 ,.66+.66+.66+.66, .66+.66+.66, .66+.66,.66,0,0,.66,.66+.66,.66+.66+.66,.66+.66+.66+.66,   .66+.66+.66+.66+.66,   .66+.66+.66+.66+.66 ,.66+.66+.66+.66, .66+.66+.66, .66+.66,.66,0,0,.66,.66+.66,.66+.66+.66,.66+.66+.66+.66,   .66+.66+.66+.66+.66};
double markar_yy[31]={0,0,0,0,0,0,0, .6,.6,.6,.6,.6,.6,1.2,1.2,1.2,1.2,1.2,1.2,1.8,1.8,1.8,1.8,1.8,1.8,2.4,2.4,2.4,2.4,2.4,2.4};

double markar_1_translate_xx=-2.17;
double markar_1_translate_yy=-1.2;

double markar_2_translate_xx=-2.17;
double markar_2_translate_yy=-1.2;



std::string stemp;

void draw_player_information()
{
    glPushMatrix();
    glColor3f(.25,.30,.74);

    stringstream convert;
    convert<<player_1_current;
    string text=convert.str();

    stemp="Player 1 : "+text;
    drawText(stemp.data(),stemp.size(),650,500);


    stringstream convert1;
    convert1<<player_2_current;
    string text1=convert1.str();
    string stemp1;
    stemp1="Player 2 : "+text1;
    drawText_1(stemp1.data(),stemp1.size(),650,450);



    string stemp2;
    stemp2="winner";
    drawText_1(stemp2.data(),stemp2.size(),555,530);





    if(player)
    {
        if(player_2_current>=30)
        {
            string stemp3;

            stemp3="Winner : Player 2";
            drawText_1(stemp3.data(),stemp3.size(),650,400);
        }
        else
        {
            string stemp3;
            stemp3="Player turn : 1";
            drawText_1(stemp3.data(),stemp3.size(),650,400);
        }


    }
    else
    {
        if(player_1_current>=30)
        {
            string stemp3;

            stemp3="Winner : Player 1";
            drawText_1(stemp3.data(),stemp3.size(),650,400);
        }
        else
        {
            string stemp3;
            stemp3="Player turn : 2";
            drawText_1(stemp3.data(),stemp3.size(),650,400);
        }

    }

            string stemp3;
            stemp3="Press space to play";
            drawText_2(stemp3.data(),stemp3.size(),650,550);


    glPopMatrix();


}


void draw_markar()
{
    glPushMatrix();
    init_markar();
    glColor3f(0,0,0);
    glTranslatef(markar_1_translate_xx+markar_xx[player_1_current],markar_1_translate_yy+markar_yy[player_1_current],0);
    glRotatef(-20,1,0,1);
    glutSolidCone(.2,1,20,20);
    light_disable();

    glPopMatrix();




    glPushMatrix();
    init_markar_1();
    glColor3f(0,0,0);
    //glTranslatef(board_ceil_x_values[0][cone_y]+(x_size/2),board_ceil_y_values[0][cone_y]+(y_size/2),0);
    //glTranslatef(.66,0,0);

    glTranslatef(markar_1_translate_xx+markar_xx[player_2_current],markar_1_translate_yy+markar_yy[player_2_current],0);
    //glRotatef(-20,1,0,1);
    //glutSolidCone(.2,1,20,20);

    glRotatef(10,1,0,0);

    glutSolidTorus(.15,.1,20,20);

    light_disable();
    glPopMatrix();



    if(player_1_current==18)
    {
        player_1_current=5;
    }
    else if(player_1_current==22)
    {
        player_1_current=11;
    }
    else if(player_1_current==12)
    {
        player_1_current=23;
    }
    else if(player_1_current==16)
    {
        player_1_current=29;
    }


    if(player_2_current==18)
    {
        player_2_current=5;
    }
    else if(player_2_current==22)
    {
        player_2_current=11;
    }
    else if(player_2_current==12)
    {
        player_2_current=23;
    }
    else if(player_2_current==16)
    {
        player_2_current=29;
    }
}

void generate_value()
{
    int player_1=1+randdom(6);
    if(player)
    {
        player_1_current+=player_1;
        if(player_1_current>=30)
        {

            player_1_current=30;

        }
        player_2=true;
        player=false;
    }
    else
    {
        player_2_current+=player_1;
        if(player_2_current>=30)
        {
            player_2_current=30;



        }
        player_2=false;
        player=true;
    }

    //cout<<player<<"  "<<player_2<<"    "<<player_1_current<<"   "<<player_2_current<<endl;
    if(player_1==1)
    {
        _angle=0;

    }
    else if(player_1==2)
    {
        rotate_y=false;
        _angle=90;
    }
    else if(player_1==3)
    {
        rotate_y=false;
        _angle=270;
    }
    else if(player_1==4)
    {
        rotate_y=false;
        _angle=180;
    }
    else if(player_1==5)
    {
        rotate_x=false;
        _angle=270;
    }
    else if(player_1==6)
    {
        rotate_x=false;
        _angle=90;
    }

}



double chokkha_waiting_time=370.0f;

void update(int value) {

    if(player_1_current>=30||player_2_current>=30)
    {
        glutPostRedisplay();
        return ;
    }

    if(snake_rotate>=0)
    {
        snake_rotate-=.05;
    }
    else
    {
        snake_rotate-=.05;
        if(snake_rotate<=-2)
        {
            snake_rotate=2;
        }
    }
    if(player_key_pressed==true)
    {
        if(translate_chokkha_y<=0)
        {
            //printf("%lf  ",_angle);

            generate_value();
            player_key_pressed=false;

            //printf("%lf  ",_angle);
            chokkha_waiting_time=0.0f;
            glutPostRedisplay();

        }
        else
        {
            translate_chokkha_y-=.01;
        }
    }
    if(chokkha_waiting_time<=360.0f)
    {
        chokkha_waiting_time+=5.0f;
    }
    else
        {
            rotate_x=true;
        rotate_y=true;

            _angle += 8.0f;
            if (_angle > 360)
                {
                    _angle -= 360;
                }
        }


	glutPostRedisplay();
	glutTimerFunc(25, update, 0);

}



void translate_chokkha()
{
    translate_chokkha_y=+1;
}
void keyboard(unsigned char key, int x, int y)
{
   if(key==' ')
   {
       chokkha_waiting_time=370;
       _angle=0.0f;
       //draw_player_information();

       translate_chokkha();

       player_key_pressed=true;
   }
   else
   {
       player_key_pressed=false;
   }
}



void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
         1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
         1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (1000,600);
   glutInitWindowPosition (20, 20);
   glutCreateWindow (argv[0]);

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutTimerFunc(25, update, 0); //Add a timer
   glutMainLoop();
   return 0;
}

void draw_chokkha()
{
    init();
    double rotate_x=0;

    glColor3f(0,0,0);

    glPushMatrix();
    glEnable(GL_DEPTH_TEST);
    rotate_chokkha();
    glRotatef(rotate_x,0,1,0);

    glutSolidCube(.5);
    light_disable();
    // --------------------chokkha ends here

    // draw cicles


    glEnable(GL_DEPTH_TEST);

    glPushMatrix();
    glTranslatef(0,0,.23);
    glutSolidSphere(.05,20,20);
    light_disable();
    glPopMatrix();

    glPopMatrix();




     glPushMatrix();
     glEnable(GL_DEPTH_TEST);
    rotate_chokkha();
    glRotatef(rotate_x-90,0,1,0);

    glTranslatef(-.1,0,.22);
    glutSolidSphere(.05,20,20);
    glTranslatef(.2,0,.00);
    glutSolidSphere(.05,20,20);
    glEnable(GL_DEPTH_TEST);
    light_disable();
    glPopMatrix();





     glPushMatrix();
     glEnable(GL_DEPTH_TEST);
     rotate_chokkha();
    glRotatef(rotate_x+90,0,1,0);

    glTranslatef(-.1,.1,.22);
    glutSolidSphere(.05,20,20);

    glTranslatef(.1,-.1,.00);
    glutSolidSphere(.05,20,20);

    glTranslatef(.1,-.1,.00);
    glutSolidSphere(.05,20,20);

    glEnable(GL_DEPTH_TEST);
    light_disable();
    glPopMatrix();










     glPushMatrix();
     glEnable(GL_DEPTH_TEST);
     rotate_chokkha();
    glRotatef(rotate_x-180,0,1,0);



    glTranslatef(-.1,.1,.22);
    glutSolidSphere(.05,20,20);

    glTranslatef(.2,0,.00);
    glutSolidSphere(.05,20,20);

    glTranslatef(-.2,-.2,.00);
    glutSolidSphere(.05,20,20);

    glTranslatef(.2,0,.00);
    glutSolidSphere(.05,20,20);


    glEnable(GL_DEPTH_TEST);
    light_disable();
    glPopMatrix();






     glPushMatrix();
     glEnable(GL_DEPTH_TEST);
     rotate_chokkha();
    glRotatef(rotate_x+270,1,0,0);


    glTranslatef(-.1,.15,.22);
    glutSolidSphere(.05,20,20);

    glTranslatef(.2,0,.00);
    glutSolidSphere(.05,20,20);

    glTranslatef(-.2,-.15,.00);
    glutSolidSphere(.05,20,20);

    glTranslatef(.2,0,.00);
    glutSolidSphere(.05,20,20);


    glTranslatef(-.2,-.15,.00);
    glutSolidSphere(.05,20,20);

    glTranslatef(.2,0,.00);
    glutSolidSphere(.05,20,20);


    glEnable(GL_DEPTH_TEST);
    light_disable();
    glPopMatrix();






    glPushMatrix();
     glEnable(GL_DEPTH_TEST);
     rotate_chokkha();
    glRotatef(rotate_x+90,1,0,0);


    glTranslatef(-.15,.15,.22);
    glutSolidSphere(.05,20,20);

    glTranslatef(.3,0,.00);
    glutSolidSphere(.05,20,20);

    glTranslatef(-.3,-.15,.00);
    glutSolidSphere(.05,20,20);

    glTranslatef(.3,0,.00);
    glutSolidSphere(.05,20,20);


    glTranslatef(-.3,-.15,.00);
    glutSolidSphere(.05,20,20);

    glTranslatef(.3,0,.00);
    glutSolidSphere(.05,20,20);

    glTranslatef(-.15,.15,.00);
    glutSolidSphere(.05,20,20);

    glEnable(GL_DEPTH_TEST);
    light_disable();
    glPopMatrix();


}
void init(void)
{
        GLfloat ambient[] = { 1.0, 1.0, 1.0, 0.0 };
        glClearColor(0.0, 0, 0, 0.0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        GLfloat mat_shininess[] = {500.0 };
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_SMOOTH);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        GLfloat light_position[] = { 1.0, 0.0, 1.0, 0.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
}

void init_markar(void)
{
        GLfloat ambient[] = { 1.0, 1.0, 1.0, 0.0 };
        glClearColor(0.0, 0, 0, 0.0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        GLfloat mat_shininess[] = {500.0 };
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_SMOOTH);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
}

void init_markar_1(void)
{
        GLfloat ambient[] = { 0, 0, 1.0, 0.0 };
        glClearColor(0.0, 0, 0, 0.0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        GLfloat mat_shininess[] = {500.0 };
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_SMOOTH);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        GLfloat light_position[] = { 0.0, 1.0, 0.0, 0.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
}
void init_snake_moutght()
{
    GLfloat ambient[] = { 1.0, 0.0, 0.5, 0.0 };glTranslatef(-.01,-.05,0);
        glClearColor(0.0, 0, 0, 0.0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        GLfloat mat_shininess[] = {500.0 };
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_SMOOTH);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
}

void init_snake_body_1()
{
    GLfloat ambient[] = { 1.0, 0.0, 0.5, 0.0 };
        glClearColor(0.0, 0, 0, 0.0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        GLfloat mat_shininess[] = {500.0 };
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_SMOOTH);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
}

/*
void init_snake_body_2()
{
    GLfloat ambient[] = { 1.0, 1.0, 1.0, 0.0 };
        glClearColor(0.0, 0, 0, 0.0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        GLfloat mat_shininess[] = {500.0 };
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_SMOOTH);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
}
*/

void init_snake_body_2()
{
    GLfloat ambient[] = { 1, 0.0, 0, 0.0 };
        glClearColor(0.0, 0, 0, 0.0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        GLfloat mat_shininess[] = {500.0 };
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_SMOOTH);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        GLfloat light_position[] = {1.0, 0.0, 0.0, 1.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
}

void init_chokkha_base()
{
    GLfloat ambient[] = { 1.0, 0.0, 1, 0.0 };
        glClearColor(0.0, 0, 0, 0.0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        GLfloat mat_shininess[] = {50.0 };
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_SMOOTH);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

        GLfloat light_position[] = { 0.0, 0.0, 1.0, 0.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
}

void drawText(const char *text, int length,double x,double y)
 {
     glMatrixMode(GL_PROJECTION);
     double *matrix=new double[16];
     glGetDoublev(GL_PROJECTION_MATRIX,matrix);
     glLoadIdentity();
     glOrtho(0,800,0,600,-5,5);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glPushMatrix();
     glLoadIdentity();
     if(text=="winner")
     {
         cout<<"yes"<<endl;
     }
     glRasterPos2f(x,y);
     for(int i=0;i<length;i++)
     {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)text[i]);
     }
     glPopMatrix();
     glMatrixMode(GL_PROJECTION);
     glLoadMatrixd(matrix);
     glMatrixMode(GL_MODELVIEW);
 }

 void drawText_1(const char *text, int length,double x,double y)
 {
     glMatrixMode(GL_PROJECTION);
     double *matrix=new double[16];
     glGetDoublev(GL_PROJECTION_MATRIX,matrix);
     glLoadIdentity();
     glOrtho(0,800,0,600,-5,5);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glPushMatrix();
     glLoadIdentity();
     if(text=="winner")
     {
         cout<<"yes"<<endl;
     }
     glRasterPos2f(x,y);
     for(int i=0;i<length;i++)
     {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)text[i]);
     }
     glPopMatrix();
     glMatrixMode(GL_PROJECTION);
     glLoadMatrixd(matrix);
     glMatrixMode(GL_MODELVIEW);
 }


 void drawText_2(const char *text, int length,double x,double y)
 {
     glMatrixMode(GL_PROJECTION);
     double *matrix=new double[16];
     glGetDoublev(GL_PROJECTION_MATRIX,matrix);
     glLoadIdentity();
     glOrtho(0,800,0,600,-5,5);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glPushMatrix();
     glLoadIdentity();
     if(text=="winner")
     {
         cout<<"yes"<<endl;
     }
     glRasterPos2f(x,y);
     for(int i=0;i<length;i++)
     {
         glutBitmapCharacter(GLUT_BITMAP_8_BY_13,(int)text[i]);
     }
     glPopMatrix();
     glMatrixMode(GL_PROJECTION);
     glLoadMatrixd(matrix);
     glMatrixMode(GL_MODELVIEW);
 }
