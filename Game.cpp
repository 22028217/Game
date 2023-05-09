
#include <SDL_mixer.h>
#include <SDL.h>
#include <bits/stdc++.h>
#include <SDL_image.h>
using namespace std;


const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Color Memory";

void logSDLError(std::ostream& os,const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();


SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

void refreshScreen1(SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *color_memory,SDL_Texture *new_game, SDL_Texture *continue_game,SDL_Texture *continue_game2,
                    SDL_Texture *quit,int x,int y, int &status,vector<int> &color_master1,vector<int> &color_master2,vector<int> &color_master3, const bool mouseDown,bool &_continue);

void refreshScreen2(SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *select,SDL_Texture *normal,SDL_Texture *normal2, SDL_Texture *difficult,SDL_Texture *difficult2,
                    SDL_Texture *nightmare,SDL_Texture *nightmare2,SDL_Texture *back_,int x,int y, int &status,int &mode,vector<int> &color_master1,vector<int> &color_master2,vector<int> &color_master3,
                    int &score1,int &score2,int &score3,int &stage1,int &stage2,int &stage3, const bool mouseDown,bool &_continue);

void refreshScreen3(SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *red1,SDL_Texture *red2,
                    SDL_Texture *orange1,SDL_Texture *orange2,SDL_Texture *yellow1,SDL_Texture *yellow2,SDL_Texture *green1,SDL_Texture *green2,
                    SDL_Texture *blue1,SDL_Texture *blue2,SDL_Texture *pink1,SDL_Texture *pink2,SDL_Texture *purple1,SDL_Texture *purple2,SDL_Texture *_round,SDL_Texture *great,
                    SDL_Texture *_0,SDL_Texture *_1,SDL_Texture *_2,SDL_Texture *_3,SDL_Texture *_4,SDL_Texture *_5,SDL_Texture *_6,SDL_Texture *_7,SDL_Texture *_8,
                    SDL_Texture *_9,Mix_Chunk *sound1, Mix_Chunk *sound2,Mix_Chunk *sound3, Mix_Chunk *sound4, Mix_Chunk *sound5, Mix_Chunk *sound6, Mix_Chunk *sound7,
                    int &status,int &mode,int &score,int &stage, vector<int> &color,vector<int> &color_master, bool &win);


void refreshScreen4_1( SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *red1,SDL_Texture *red2,
                       SDL_Texture *orange1,SDL_Texture *orange2,SDL_Texture *yellow1,SDL_Texture *yellow2,SDL_Texture *back_,
                       SDL_Texture *_0,SDL_Texture *_1,SDL_Texture *_2,SDL_Texture *_3,SDL_Texture *_4,SDL_Texture *_5,SDL_Texture *_6,SDL_Texture *_7,
                       SDL_Texture *_8,SDL_Texture *_9,SDL_Texture *score_txt,SDL_Texture *highest_record,SDL_Texture *watch_again,Mix_Chunk *win_sound,Mix_Chunk *sound1, Mix_Chunk *sound2,
                       Mix_Chunk *sound3,int x,int y,int &status,int &score,int &record,int &stage, vector<int> &color, vector<int> &color_master,const bool mouseDown,bool &win);

void refreshScreen4_2( SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *red1,SDL_Texture *red2,
                       SDL_Texture *orange1,SDL_Texture *orange2,SDL_Texture *yellow1,SDL_Texture *yellow2,SDL_Texture *green1,SDL_Texture *green2,
                       SDL_Texture *blue1,SDL_Texture *blue2,SDL_Texture *back_,
                       SDL_Texture *_0,SDL_Texture *_1,SDL_Texture *_2,SDL_Texture *_3,SDL_Texture *_4,SDL_Texture *_5,SDL_Texture *_6,SDL_Texture *_7,
                       SDL_Texture *_8,SDL_Texture *_9,SDL_Texture *score_txt,SDL_Texture *highest_record,SDL_Texture *watch_again,Mix_Chunk *win_sound,Mix_Chunk *sound1, Mix_Chunk *sound2,
                       Mix_Chunk *sound3, Mix_Chunk *sound4, Mix_Chunk *sound5,
                       int x,int y,int &status,int &score,int &stage,int &record, vector<int> &color, vector<int> &color_master,const bool mouseDown,bool &win);

void refreshScreen4_3( SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *red1,SDL_Texture *red2,
                       SDL_Texture *orange1,SDL_Texture *orange2,SDL_Texture *yellow1,SDL_Texture *yellow2,SDL_Texture *green1,SDL_Texture *green2,
                       SDL_Texture *blue1,SDL_Texture *blue2,SDL_Texture *pink1,SDL_Texture *pink2,SDL_Texture *purple1,SDL_Texture *purple2,SDL_Texture *back_,
                       SDL_Texture *_0,SDL_Texture *_1,SDL_Texture *_2,SDL_Texture *_3,SDL_Texture *_4,SDL_Texture *_5,SDL_Texture *_6,SDL_Texture *_7,
                       SDL_Texture *_8,SDL_Texture *_9,SDL_Texture *score_txt,SDL_Texture *highest_record,SDL_Texture *watch_again,Mix_Chunk *win_sound,Mix_Chunk *sound1, Mix_Chunk *sound2,
                       Mix_Chunk *sound3, Mix_Chunk *sound4, Mix_Chunk *sound5, Mix_Chunk *sound6, Mix_Chunk *sound7,
                       int x,int y,int &status,int &score,int &stage,int &record, vector<int> &color, vector<int> &color_master,const bool mouseDown,bool &win);

void refreshScreenOver(SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *gameOver,SDL_Texture *play_again,SDL_Texture *menu, int x, int y,
                       int &status, const bool mouseDown);


int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    int status=1;
    vector<int> color1,color_master1;
    vector<int> color2,color_master2;
    vector<int> color3,color_master3;
    ifstream file;
    file.open("record.txt");
    string s;
    getline(file,s);
    int record1=stoi(s);
    getline(file,s);
    int record2=stoi(s);
    getline(file,s);
    int record3=stoi(s);
    getline(file,s);
    int score1=stoi(s);
    getline(file,s);
    int score2=stoi(s);
    getline(file,s);
    int score3=stoi(s);
    getline(file,s);
    int stage1=stoi(s);
    getline(file,s);
    int stage2=stoi(s);
    getline(file,s);
    int stage3=stoi(s);
    getline(file,s);
    if((int)s[0]<55)
    {
        for(int i=0; i<s.size(); i++)
        {
            int tmp=((int) s[i])-48;
            color_master1.push_back(tmp);
        }
    }
    getline(file,s);
    if((int)s[0]<55)
    {
        for(int i=0; i<s.size(); i++)
        {
            int tmp=((int) s[i])-48;
            color_master2.push_back(tmp);
        }
    }
    getline(file,s);
    if((int)s[0]<55)
    {
        for(int i=0; i<s.size(); i++)
        {
            int tmp=((int) s[i])-48;
            color_master3.push_back(tmp);
        }
    }
    file.close();
    int mode;
    bool win=false;
    bool _continue=false;




    SDL_Event e;

    SDL_Texture *background = loadTexture("picture/background.bmp", renderer);
    SDL_Texture *red1=loadTexture("picture/red1.bmp",renderer);
    SDL_Texture *red2=loadTexture("picture/red2.bmp",renderer);
    SDL_Texture *yellow1=loadTexture("picture/yellow1.bmp",renderer);
    SDL_Texture *yellow2=loadTexture("picture/yellow2.bmp",renderer);
    SDL_Texture *orange1=loadTexture("picture/orange1.bmp",renderer);
    SDL_Texture *orange2=loadTexture("picture/orange2.bmp",renderer);
    SDL_Texture *green1=loadTexture("picture/green1.bmp",renderer);
    SDL_Texture *green2=loadTexture("picture/green2.bmp",renderer);
    SDL_Texture *blue1=loadTexture("picture/blue1.bmp",renderer);
    SDL_Texture *blue2=loadTexture("picture/blue2.bmp",renderer);
    SDL_Texture *pink1=loadTexture("picture/pink1.bmp",renderer);
    SDL_Texture *pink2=loadTexture("picture/pink2.bmp",renderer);
    SDL_Texture *purple1=loadTexture("picture/purple1.bmp",renderer);
    SDL_Texture *purple2=loadTexture("picture/purple2.bmp",renderer);
    SDL_Texture *gameOver=loadTexture("picture/gameOver.png",renderer);
    SDL_Texture *color_memory=loadTexture("picture/color_memory.png",renderer);
    SDL_Texture *new_game=loadTexture("picture/new_game.png",renderer);
    SDL_Texture *continue_game=loadTexture("picture/continue.png",renderer);
    SDL_Texture *continue_game2=loadTexture("picture/continue2.png",renderer);
    SDL_Texture *quit=loadTexture("picture/quit.png",renderer);
    SDL_Texture *select=loadTexture("picture/select_the_mode.png",renderer);
    SDL_Texture *normal=loadTexture("picture/normal.png",renderer);
    SDL_Texture *normal2=loadTexture("picture/normal2.png",renderer);
    SDL_Texture *difficult=loadTexture("picture/diff.png",renderer);
    SDL_Texture *difficult2=loadTexture("picture/diff2.png",renderer);
    SDL_Texture *nightmare=loadTexture("picture/nightmare.png",renderer);
    SDL_Texture *nightmare2=loadTexture("picture/nightmare2.png",renderer);
    SDL_Texture *back_=loadTexture("picture/back.png",renderer);
    SDL_Texture *score_txt=loadTexture("picture/score.png",renderer);
    SDL_Texture *_round=loadTexture("picture/round.png",renderer);
    SDL_Texture *highest_record=loadTexture("picture/highest_record.png",renderer);
    SDL_Texture *_1=loadTexture("picture/1.png",renderer);
    SDL_Texture *_2=loadTexture("picture/2.png",renderer);
    SDL_Texture *_3=loadTexture("picture/3.png",renderer);
    SDL_Texture *_4=loadTexture("picture/4.png",renderer);
    SDL_Texture *_5=loadTexture("picture/5.png",renderer);
    SDL_Texture *_6=loadTexture("picture/6.png",renderer);
    SDL_Texture *_7=loadTexture("picture/7.png",renderer);
    SDL_Texture *_8=loadTexture("picture/8.png",renderer);
    SDL_Texture *_9=loadTexture("picture/9.png",renderer);
    SDL_Texture *_0=loadTexture("picture/0.png",renderer);
    SDL_Texture *play_again=loadTexture("picture/play_again.png",renderer);
    SDL_Texture *menu=loadTexture("picture/menu.png",renderer);
    SDL_Texture *watch_again=loadTexture("picture/watch_again.png",renderer);
    SDL_Texture *great=loadTexture("picture/great.png",renderer);

    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    Mix_Chunk *win_sound=Mix_LoadWAV("sound/win_sound.mp3");
    Mix_Chunk *sound1=Mix_LoadWAV("sound/sound1.mp3");
    Mix_Chunk *sound2=Mix_LoadWAV("sound/sound2.mp3");
    Mix_Chunk *sound3=Mix_LoadWAV("sound/sound3.mp3");
    Mix_Chunk *sound4=Mix_LoadWAV("sound/sound4.mp3");
    Mix_Chunk *sound5=Mix_LoadWAV("sound/sound5.mp3");
    Mix_Chunk *sound6=Mix_LoadWAV("sound/sound6.mp3");
    Mix_Chunk *sound7=Mix_LoadWAV("sound/sound7.mp3");


    while (true)
    {


        SDL_Delay(10);


        if ( SDL_WaitEvent(&e) == 0) continue;


        if (e.type == SDL_QUIT) break;


        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;

        if (status==0) break;


        if(status==3)
        {
            status=4;

            if(mode==1)
            {

                refreshScreen3(renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,green1,green2,
                               blue1,blue2,pink1,pink2,purple1,purple2,_round,great,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,sound1, sound2, sound3, sound4, sound5,
                               sound6, sound7,status,mode,score1,stage1,color1,color_master1,win);
                refreshScreen4_1( renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,back_,_0,_1,_2,_3,_4,_5,
                                  _6,_7,_8,_9,score_txt,highest_record,watch_again,win_sound,sound1,sound2,sound3,
                                  1200,600,status,score1,record1,stage1, color1,color_master1,false,win);
            }
            if(mode==2)
            {
                refreshScreen3(renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,green1,green2,
                               blue1,blue2,pink1,pink2,purple1,purple2,_round,great,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,sound1, sound2, sound3, sound4, sound5,
                               sound6, sound7,status,mode,score2,stage2,color2,color_master2,win);
                refreshScreen4_2( renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,green1,green2,
                                  blue1,blue2,back_,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,score_txt,highest_record,
                                  watch_again,win_sound,sound1,sound2,sound3, sound4, sound5,
                                  1200,600,status,score2,stage2,record2, color2,color_master2,false,win);

            }
            if(mode==3)
            {
                refreshScreen3(renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,green1,green2,
                               blue1,blue2,pink1,pink2,purple1,purple2,_round,great,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,sound1, sound2, sound3, sound4, sound5,
                               sound6, sound7,status,mode,score3,stage3,color3,color_master3,win);
                refreshScreen4_3(renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,green1,green2,blue1,
                                 blue2,pink1,pink2,purple1,purple2,back_,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,score_txt,highest_record,watch_again,
                                 win_sound,sound1, sound2, sound3, sound4, sound5, sound6, sound7,
                                 1200,600,status,score3,stage3,record3,color3,color_master3,false,win);
            }

        }
        if(status==1)
        {

            status=-1;
            refreshScreen1(renderer,background,color_memory,new_game,continue_game,continue_game2,
                            quit,1200,600,status,color_master1,color_master2,color_master3,false,_continue);

        }
        if(status==2)
        {
            status=-2;
            refreshScreen2(renderer,background,select,normal,normal2,difficult,difficult2,nightmare,nightmare2,back_,
                           1200,600,status,mode,color_master1,color_master2,color_master3,
                           score1,score2,score3,stage1,stage2,stage3,false,_continue);
        }
        if(status==99)
        {

            refreshScreenOver(renderer,background,gameOver,play_again,menu,1200,600,status,false);
        }


        if (e.type == SDL_MOUSEBUTTONDOWN||e.type == SDL_MOUSEMOTION)
        {

            int x = e.button.x;
            int y = e.button.y;



            if (e.type == SDL_MOUSEBUTTONDOWN)
            {


                if(status==4)
                {
                    if(mode==1)
                    {
                        refreshScreen4_1( renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,back_,_0,_1,_2,_3,_4,_5,
                                          _6,_7,_8,_9,score_txt,highest_record,watch_again,win_sound,sound1,sound2,sound3,
                                          x,y,status,score1,record1,stage1, color1,color_master1,true,win);
                    }
                    if(mode==2)
                    {
                        refreshScreen4_2( renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,green1,green2,
                                          blue1,blue2,back_,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,score_txt,highest_record,
                                          watch_again,win_sound,sound1,sound2,sound3, sound4, sound5,
                                          x,y,status,score2,stage2,record2, color2,color_master2,true,win);

                    }
                    if(mode==3)
                    {
                        refreshScreen4_3(renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,green1,green2,blue1,
                                         blue2,pink1,pink2,purple1,purple2,back_,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,score_txt,highest_record,watch_again,win_sound,
                                         sound1, sound2, sound3, sound4, sound5, sound6, sound7,
                                         x,y,status,score3,stage3,record3,color3,color_master3,true,win);
                    }
                }
                if(status==-1)
                {
                    refreshScreen1(renderer,background,color_memory,new_game,continue_game,continue_game2,
                                    quit,x,y,status,color_master1,color_master2,color_master3,true,_continue);

                }
                if(status==-2)
                {
                    refreshScreen2(renderer,background,select,normal,normal2,difficult,difficult2,nightmare,
                                   nightmare2,back_,x,y,status,mode,color_master1,color_master2,color_master3,
                                   score1,score2,score3,stage1,stage2,stage3,true,_continue);
                }
                if(status==99)
                {

                    refreshScreenOver(renderer,background,gameOver,play_again,menu,x,y,status,true);

                }

            }

        }
        if (e.type == SDL_MOUSEBUTTONUP)
        {

            int x = e.button.x;
            int y = e.button.y;
            SDL_Delay(100);

            if(status==4)
            {
                if(mode==1)
                {
                    refreshScreen4_1( renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,back_,_0,_1,_2,_3,_4,_5,
                                      _6,_7,_8,_9,score_txt,highest_record,watch_again,win_sound,sound1,sound2,sound3,
                                      x,y,status,score1,record1,stage1, color1,color_master1,false,win);
                }
                if(mode==2)
                {
                    refreshScreen4_2( renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,green1,green2,
                                      blue1,blue2,back_,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,score_txt,highest_record,
                                      watch_again,win_sound,sound1,sound2,sound3, sound4, sound5,
                                      x,y,status,score2,stage2,record2, color2,color_master2,false,win);

                }
                if(mode==3)
                {
                    refreshScreen4_3(renderer,background,red1,red2,orange1,orange2,yellow1,yellow2,green1,green2,blue1,
                                     blue2,pink1,pink2,purple1,purple2,back_,_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,score_txt,highest_record,watch_again,win_sound,
                                     sound1, sound2, sound3, sound4, sound5, sound6, sound7,
                                     x,y,status,score3,stage3,record3,color3,color_master3,false,win);
                }
            }
            if(status==99) refreshScreenOver(renderer,background,gameOver,play_again,menu,x,y,status,false);

        }
        ofstream _file;
        _file.open("record.txt",ios::out);
        _file<<record1<<endl;
        _file<<record2<<endl;
        _file<<record3<<endl;
        _file<<score1<<endl;
        _file<<score2<<endl;
        _file<<score3<<endl;
        _file<<stage1<<endl;
        _file<<stage2<<endl;
        _file<<stage3<<endl;
        string emp="n";
        if(color_master1.size()==0)
        {
            _file<<emp<<endl;
        }
        else
        {
            for(int i=0; i<color_master1.size(); i++) _file<<color_master1[i];
            _file<<endl;
        }
        if(color_master2.size()==0)
        {
            _file<<emp<<endl;
        }
        else
        {
            for(int i=0; i<color_master2.size(); i++) _file<<color_master2[i];
            _file<<endl;
        }
        if(color_master3.size()==0)
        {
            _file<<emp<<endl;
        }
        else
        {
            for(int i=0; i<color_master3.size(); i++) _file<<color_master3[i];
            _file<<endl;
        }
        _file.close();


    }

    quitSDL(window, renderer);
    return 0;
}

void refreshScreen1(SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *color_memory,SDL_Texture *new_game, SDL_Texture *continue_game,SDL_Texture *continue_game2,
                    SDL_Texture *quit,int x,int y, int &status,vector<int> &color_master1,vector<int> &color_master2,vector<int> &color_master3, const bool mouseDown,bool &_continue)
{
    int check=color_master1.size()+color_master2.size()+color_master3.size();
    if(!mouseDown)
    {
        renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        renderTexture(color_memory,renderer,255,100,690,80);
        if(check) renderTexture(continue_game,renderer,450,255,300,45);
        else renderTexture(continue_game2,renderer,450,255,300,45);
        renderTexture(new_game,renderer,445,320,310,45);
        renderTexture(quit,renderer,530,380,140,55);
        SDL_RenderPresent(renderer);
    }
    else
    {

        if(255<=y&&y<=300&&450<=x&&x<=750)
        {
            if(check)
            {
                status=2;
                _continue=true;
            }
        }
        if(320<=y&&y<=365&&445<=x&&x<=755)
        {
            status=2;
            _continue=false;
        }
        if(380<=y&&y<=435&&530<=x&&x<=670)
        {
            status=0;
        }

    }
}

void refreshScreen2(SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *select,SDL_Texture *normal,SDL_Texture *normal2, SDL_Texture *difficult,
                    SDL_Texture *difficult2,SDL_Texture *nightmare,SDL_Texture *nightmare2,SDL_Texture *back_,int x,int y, int &status,int &mode,
                    vector<int> &color_master1,vector<int> &color_master2,vector<int> &color_master3,
                    int &score1,int &score2,int &score3,int &stage1,int &stage2,int &stage3, const bool mouseDown,bool &_continue)
{
    int check1=color_master1.size();
    int check2=color_master2.size();
    int check3=color_master3.size();
    if(!mouseDown)
    {
        renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        renderTexture(select,renderer,250,100,700,80);
        if(_continue&&!check1) renderTexture(normal2,renderer,470,200,260,50);
        else renderTexture(normal,renderer,470,200,260,50);
        if(_continue&&!check2) renderTexture(difficult2,renderer,455,300,290,50);
        else renderTexture(difficult,renderer,455,300,290,50);
        if(_continue&&!check3) renderTexture(nightmare2,renderer,425,400,350,50);
        else renderTexture(nightmare,renderer,425,400,350,50);
        renderTexture(back_,renderer,550,500,100,30);
        SDL_RenderPresent(renderer);


    }
    else
    {
        if(470<=x&&x<=730&&200<=y&&y<=260)
        {
            if(!_continue)
            {
                int stage1=1;
                score1=0;
                color_master1.erase(color_master1.begin(),color_master1.end());
                status=3;
                mode=1;
            }
            else if(color_master1.size()!=0)
            {
                status=3;
                mode=1;
            }

        }
        if(455<=x&&x<=745&&300<=y&&y<=350)
        {
            if(!_continue)
            {
                int stage2=1;
                score2=0;
                color_master2.erase(color_master2.begin(),color_master2.end());
                status=3;
                mode=2;
            }
            else if(color_master2.size()!=0)
            {
                status=3;
                mode=2;
            }
        }
        if(425<=x&&x<=775&&y>=400&&450>=y)
        {
            if(!_continue)
            {
                int stage3=1;
                score2=0;
                color_master3.erase(color_master3.begin(),color_master3.end());
                status=3;
                mode=3;
            }
            else if(color_master3.size()!=0)
            {
                status=3;
                mode=3;
            }
        }
        if(550<=x&&x<=650&&500<=y&&y<=530)
        {
            status=1;
        }

    }

}

void refreshScreen3(SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *red1,SDL_Texture *red2,
                    SDL_Texture *orange1,SDL_Texture *orange2,SDL_Texture *yellow1,SDL_Texture *yellow2,SDL_Texture *green1,SDL_Texture *green2,
                    SDL_Texture *blue1,SDL_Texture *blue2,SDL_Texture *pink1,SDL_Texture *pink2,SDL_Texture *purple1,SDL_Texture *purple2,SDL_Texture *_round,SDL_Texture *great,
                    SDL_Texture *_0,SDL_Texture *_1,SDL_Texture *_2,SDL_Texture *_3,SDL_Texture *_4,SDL_Texture *_5,SDL_Texture *_6,SDL_Texture *_7,SDL_Texture *_8,
                    SDL_Texture *_9,Mix_Chunk *sound1, Mix_Chunk *sound2,Mix_Chunk *sound3, Mix_Chunk *sound4, Mix_Chunk *sound5, Mix_Chunk *sound6, Mix_Chunk *sound7,
                    int &status,int &mode,int &score,int &stage, vector<int> &color,vector<int> &color_master,bool &win)
{
    if(score==0)
    {
        int n;
        if(mode==1) n=3;
        if(mode==2) n=5;
        if(mode==3) n=7;
        color_master.erase(color_master.begin(),color_master.end());
        for(int i=0; i<n; i++)
        {
            int tmp=rand()%n;

            color_master.push_back(tmp);
        }

    }
    if(score==-1) score++;
    color=color_master;
    if(win)
    {
        win=false;
        renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        renderTexture(great,renderer,450,200,210,50);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }
    int tmp=stage;
    int post=750;

    renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    renderTexture(_round,renderer,450,200,210,45);
    while(tmp>0)
    {
        int num=tmp%10;
        switch(num)
        {
        case 0:
            renderTexture(_0,renderer,post-40,200,40, 45);
            break;
        case 1:
            renderTexture(_1,renderer,post-40,200,40, 45);
            break;
        case 2:
            renderTexture(_2,renderer,post-40,200,40, 45);
            break;
        case 3:
            renderTexture(_3,renderer,post-40,200,40, 45);
            break;
        case 4:
            renderTexture(_4,renderer,post-40,200,40, 45);
            break;
        case 5:
            renderTexture(_5,renderer,post-40,200,40, 45);
            break;
        case 6:
            renderTexture(_6,renderer,post-40,200,40, 45);
            break;
        case 7:
            renderTexture(_7,renderer,post-40,200,40, 45);
            break;
        case 8:
            renderTexture(_8,renderer,post-40,200,40, 45);
            break;
        case 9:
            renderTexture(_9,renderer,post-40,200,40, 45);
            break;
        }
        tmp=tmp/10;
        post-=40;
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(1500);

    renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    int n=color_master.size();
    for(int i=0; i<n; i++)
    {
        int pos_x=SCREEN_WIDTH/2-75;
        int pos_y=SCREEN_HEIGHT/2-50;
        if(mode==2)
        {
            pos_x=pos_x-225+(rand()%4)*150;
            pos_y=pos_y-150+(rand()%4)*100;

        }
        if(mode==3)
        {
            pos_x=(rand()%8)*150;
            pos_y=(rand()%6)*100;
        }
        renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        switch(color[i])
        {
        case 0:
            renderTexture(red1,renderer,pos_x, pos_y,150,100);
            Mix_PlayChannel( -1, sound1, 0 );
            break;
        case 1:
            renderTexture(orange1,renderer,pos_x,pos_y,150,100);
            Mix_PlayChannel( -1, sound2, 0 );
            break;
        case 2:
            renderTexture(yellow1,renderer,pos_x,pos_y,150,100);
            Mix_PlayChannel( -1, sound3, 0 );
            break;
        case 3:
            renderTexture(green1,renderer,pos_x,pos_y,150,100);
            Mix_PlayChannel( -1, sound4, 0 );
            break;
        case 4:
            renderTexture(blue1,renderer,pos_x,pos_y,150,100);
            Mix_PlayChannel( -1, sound5, 0 );
            break;
        case 5:
            renderTexture(pink1,renderer,pos_x,pos_y,150,100);
            Mix_PlayChannel( -1, sound6, 0 );
            break;
        case 6:
            renderTexture(purple1,renderer,pos_x,pos_y,150,100);
            Mix_PlayChannel( -1, sound7, 0 );
            break;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        SDL_RenderPresent(renderer);
        SDL_Delay(500);

    }

}

void refreshScreen4_1( SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *red1,SDL_Texture *red2,
                       SDL_Texture *orange1,SDL_Texture *orange2,SDL_Texture *yellow1,SDL_Texture *yellow2,SDL_Texture *back_,
                       SDL_Texture *_0,SDL_Texture *_1,SDL_Texture *_2,SDL_Texture *_3,SDL_Texture *_4,SDL_Texture *_5,SDL_Texture *_6,SDL_Texture *_7,
                       SDL_Texture *_8,SDL_Texture *_9,SDL_Texture *score_txt,SDL_Texture *highest_record,SDL_Texture *watch_again,
                       Mix_Chunk *win_sound,Mix_Chunk *sound1, Mix_Chunk *sound2,Mix_Chunk *sound3,int x,int y,int &status,int &score,
                       int &record,int &stage, vector<int> &color, vector<int> &color_master,const bool mouseDown,bool &win)
{



    if(!mouseDown)
    {

        renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        renderTexture(red1,renderer,375,SCREEN_HEIGHT/2,150,100);
        renderTexture(orange1,renderer,375+150*1,SCREEN_HEIGHT/2,150,100);
        renderTexture(yellow1,renderer,375+150*2,SCREEN_HEIGHT/2,150,100);
        renderTexture(back_,renderer,20,20,100,30);
        renderTexture(score_txt,renderer,850,100,195,45);
        renderTexture(highest_record,renderer,534,50,520,45);
        renderTexture(watch_again,renderer,475,500,250,45);
        int tmp=score;
        int post=1200;
        if(tmp==0) renderTexture(_0,renderer,post-50,100,40,45);
        while(tmp>0)
        {
            int num=tmp%10;
            switch(num)
            {
            case 0:
                renderTexture(_0,renderer,post-40,100,40, 45);
                break;
            case 1:
                renderTexture(_1,renderer,post-40,100,40, 45);
                break;
            case 2:
                renderTexture(_2,renderer,post-40,100,40, 45);
                break;
            case 3:
                renderTexture(_3,renderer,post-40,100,40, 45);
                break;
            case 4:
                renderTexture(_4,renderer,post-40,100,40, 45);
                break;
            case 5:
                renderTexture(_5,renderer,post-40,100,40, 45);
                break;
            case 6:
                renderTexture(_6,renderer,post-40,100,40, 45);
                break;
            case 7:
                renderTexture(_7,renderer,post-40,100,40, 45);
                break;
            case 8:
                renderTexture(_8,renderer,post-40,100,40, 45);
                break;
            case 9:
                renderTexture(_9,renderer,post-40,100,40, 45);
                break;
            }
            tmp=tmp/10;
            post-=40;
        }
        tmp=record;
        post=1200;
        if(tmp==0) renderTexture(_0,renderer,post-50,50,40,45);
        while(tmp>0)
        {
            int num=tmp%10;
            switch(num)
            {
            case 0:
                renderTexture(_0,renderer,post-40,50,40, 45);
                break;
            case 1:
                renderTexture(_1,renderer,post-40,50,40, 45);
                break;
            case 2:
                renderTexture(_2,renderer,post-40,50,40, 45);
                break;
            case 3:
                renderTexture(_3,renderer,post-40,50,40, 45);
                break;
            case 4:
                renderTexture(_4,renderer,post-40,50,40, 45);
                break;
            case 5:
                renderTexture(_5,renderer,post-40,50,40, 45);
                break;
            case 6:
                renderTexture(_6,renderer,post-40,50,40, 45);
                break;
            case 7:
                renderTexture(_7,renderer,post-40,50,40, 45);
                break;
            case 8:
                renderTexture(_8,renderer,post-40,50,40, 45);
                break;
            case 9:
                renderTexture(_9,renderer,post-40,50,40, 45);
                break;
            }
            tmp=tmp/10;
            post-=40;
        }

    }
    else
    {

        if(x<=120&&y<=50)
        {
            status=1;
        }
        if(475<=x&&x<=725&&500<=y&&y<=545)
        {
            if(score>5)
            {
                score=score-5;
            }
            else score=-1;
            status=3;
        }

        int button;
        if(375<=x&&x<=825&&300<=y&&y<=400)
        {

            renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
            renderTexture(back_,renderer,20,20,100,30);
            renderTexture(score_txt,renderer,850,100,195,45);
            renderTexture(highest_record,renderer,534,50,520,45);
            renderTexture(watch_again,renderer,475,500,250,45);
            int tmp=score;
            int post=1200;
            if(tmp==0) renderTexture(_0,renderer,post-50,100,40,45);
            while(tmp>0)
            {
                int num=tmp%10;
                switch(num)
                {
                case 0:
                    renderTexture(_0,renderer,post-40,100,40, 45);
                    break;
                case 1:
                    renderTexture(_1,renderer,post-40,100,40, 45);
                    break;
                case 2:
                    renderTexture(_2,renderer,post-40,100,40, 45);
                    break;
                case 3:
                    renderTexture(_3,renderer,post-40,100,40, 45);
                    break;
                case 4:
                    renderTexture(_4,renderer,post-40,100,40, 45);
                    break;
                case 5:
                    renderTexture(_5,renderer,post-40,100,40, 45);
                    break;
                case 6:
                    renderTexture(_6,renderer,post-40,100,40, 45);
                    break;
                case 7:
                    renderTexture(_7,renderer,post-40,100,40, 45);
                    break;
                case 8:
                    renderTexture(_8,renderer,post-40,100,40, 45);
                    break;
                case 9:
                    renderTexture(_9,renderer,post-40,100,40, 45);
                    break;


                }
                tmp=tmp/10;
                post-=40;
            }
            tmp=record;
            post=1200;
            if(tmp==0) renderTexture(_0,renderer,post-50,50,40,45);
            while(tmp>0)
            {
                int num=tmp%10;
                switch(num)
                {
                case 0:
                    renderTexture(_0,renderer,post-40,50,40, 45);
                    break;
                case 1:
                    renderTexture(_1,renderer,post-40,50,40, 45);
                    break;
                case 2:
                    renderTexture(_2,renderer,post-40,50,40, 45);
                    break;
                case 3:
                    renderTexture(_3,renderer,post-40,50,40, 45);
                    break;
                case 4:
                    renderTexture(_4,renderer,post-40,50,40, 45);
                    break;
                case 5:
                    renderTexture(_5,renderer,post-40,50,40, 45);
                    break;
                case 6:
                    renderTexture(_6,renderer,post-40,50,40, 45);
                    break;
                case 7:
                    renderTexture(_7,renderer,post-40,50,40, 45);
                    break;
                case 8:
                    renderTexture(_8,renderer,post-40,50,40, 45);
                    break;
                case 9:
                    renderTexture(_9,renderer,post-40,50,40, 45);
                    break;
                }
                tmp=tmp/10;
                post-=40;
            }


            switch(x)
            {
            case 375 ... 525:
                button=0;
                renderTexture(red2,renderer,375+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound1, 0 );
                break;
            case 526 ... 675:
                button=1;
                renderTexture(orange2,renderer,375+150*1+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound2, 0 );
                break;
            case 676 ... 825:
                button=2;
                renderTexture(yellow2,renderer,375+150*2+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound3, 0 );
                break;

            }


            if(button!=0) renderTexture(red1,renderer,375,SCREEN_HEIGHT/2,150,100);
            if(button!=1)renderTexture(orange1,renderer,375+150*1,SCREEN_HEIGHT/2,150,100);
            if(button!=2)renderTexture(yellow1,renderer,375+150*2,SCREEN_HEIGHT/2,150,100);


            if(button==color[0])
            {
                if(color.size()!=0)
                {
                    color.erase(color.begin());
                    score++;
                    if(score>=record) record=score;
                    if(color.size()==0)
                    {
                        int new_= rand()%3;
                        color_master.push_back(new_);
                        if(color.size()==0)
                        {
                            win=true;
                            stage++;
                            Mix_PlayChannel( -1, win_sound, 0 );
                            status=3;

                        }

                    }
                }

            }
            else
            {
                color_master.erase(color_master.begin(),color_master.end());
                status=99;
                score=0;
                stage=1;
            }
        }

    }



    SDL_RenderPresent(renderer);


}



void refreshScreen4_2( SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *red1,SDL_Texture *red2,
                       SDL_Texture *orange1,SDL_Texture *orange2,SDL_Texture *yellow1,SDL_Texture *yellow2,SDL_Texture *green1,SDL_Texture *green2,
                       SDL_Texture *blue1,SDL_Texture *blue2,SDL_Texture *back_,
                       SDL_Texture *_0,SDL_Texture *_1,SDL_Texture *_2,SDL_Texture *_3,SDL_Texture *_4,SDL_Texture *_5,SDL_Texture *_6,SDL_Texture *_7,
                       SDL_Texture *_8,SDL_Texture *_9,SDL_Texture *score_txt,SDL_Texture *highest_record,SDL_Texture *watch_again,
                       Mix_Chunk *win_sound,Mix_Chunk *sound1, Mix_Chunk *sound2,Mix_Chunk *sound3, Mix_Chunk *sound4, Mix_Chunk *sound5,
                       int x,int y,int &status,int &score,int &stage,int &record, vector<int> &color, vector<int> &color_master,const bool mouseDown,bool &win)
{



    if(!mouseDown)
    {

        renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        renderTexture(red1,renderer,225,SCREEN_HEIGHT/2,150,100);
        renderTexture(orange1,renderer,225+150*1,SCREEN_HEIGHT/2,150,100);
        renderTexture(yellow1,renderer,225+150*2,SCREEN_HEIGHT/2,150,100);
        renderTexture(green1,renderer,225+150*3,SCREEN_HEIGHT/2,150,100);
        renderTexture(blue1,renderer,225+150*4,SCREEN_HEIGHT/2,150,100);

        renderTexture(back_,renderer,20,20,100,30);
        renderTexture(score_txt,renderer,850,100,195,45);
        renderTexture(highest_record,renderer,534,50,520,45);
        renderTexture(watch_again,renderer,475,500,250,45);
        int tmp=score;
        int post=1200;
        if(tmp==0) renderTexture(_0,renderer,post-50,100,40,45);
        while(tmp>0)
        {
            int num=tmp%10;
            switch(num)
            {
            case 0:
                renderTexture(_0,renderer,post-40,100,40, 45);
                break;
            case 1:
                renderTexture(_1,renderer,post-40,100,40, 45);
                break;
            case 2:
                renderTexture(_2,renderer,post-40,100,40, 45);
                break;
            case 3:
                renderTexture(_3,renderer,post-40,100,40, 45);
                break;
            case 4:
                renderTexture(_4,renderer,post-40,100,40, 45);
                break;
            case 5:
                renderTexture(_5,renderer,post-40,100,40, 45);
                break;
            case 6:
                renderTexture(_6,renderer,post-40,100,40, 45);
                break;
            case 7:
                renderTexture(_7,renderer,post-40,100,40, 45);
                break;
            case 8:
                renderTexture(_8,renderer,post-40,100,40, 45);
                break;
            case 9:
                renderTexture(_9,renderer,post-40,100,40, 45);
                break;
            }
            tmp=tmp/10;
            post-=40;
        }
        tmp=record;
        post=1200;
        if(tmp==0) renderTexture(_0,renderer,post-50,50,40,45);
        while(tmp>0)
        {
            int num=tmp%10;
            switch(num)
            {
            case 0:
                renderTexture(_0,renderer,post-40,50,40, 45);
                break;
            case 1:
                renderTexture(_1,renderer,post-40,50,40, 45);
                break;
            case 2:
                renderTexture(_2,renderer,post-40,50,40, 45);
                break;
            case 3:
                renderTexture(_3,renderer,post-40,50,40, 45);
                break;
            case 4:
                renderTexture(_4,renderer,post-40,50,40, 45);
                break;
            case 5:
                renderTexture(_5,renderer,post-40,50,40, 45);
                break;
            case 6:
                renderTexture(_6,renderer,post-40,50,40, 45);
                break;
            case 7:
                renderTexture(_7,renderer,post-40,50,40, 45);
                break;
            case 8:
                renderTexture(_8,renderer,post-40,50,40, 45);
                break;
            case 9:
                renderTexture(_9,renderer,post-40,50,40, 45);
                break;
            }
            tmp=tmp/10;
            post-=40;
        }
    }
    else
    {

        if(x<=120&&y<=50)
        {
            status=1;
        }
        if(475<=x&&x<=725&&500<=y&&y<=545)
        {
            if(score>5)
            {
                score=score-5;
            }
            else score=-1;
            status=3;
        }

        int button;
        if(225<=x&&x<=975&&300<=y&&y<=400)
        {

            renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
            renderTexture(back_,renderer,20,20,100,30);
            renderTexture(score_txt,renderer,850,100,195,45);
            renderTexture(highest_record,renderer,534,50,520,45);
            renderTexture(watch_again,renderer,475,500,250,45);
            int tmp=score;
            int post=1200;
            if(tmp==0) renderTexture(_0,renderer,post-50,100,40,45);
            while(tmp>0)
            {
                int num=tmp%10;
                switch(num)
                {
                case 0:
                    renderTexture(_0,renderer,post-40,100,40, 45);
                    break;
                case 1:
                    renderTexture(_1,renderer,post-40,100,40, 45);
                    break;
                case 2:
                    renderTexture(_2,renderer,post-40,100,40, 45);
                    break;
                case 3:
                    renderTexture(_3,renderer,post-40,100,40, 45);
                    break;
                case 4:
                    renderTexture(_4,renderer,post-40,100,40, 45);
                    break;
                case 5:
                    renderTexture(_5,renderer,post-40,100,40, 45);
                    break;
                case 6:
                    renderTexture(_6,renderer,post-40,100,40, 45);
                    break;
                case 7:
                    renderTexture(_7,renderer,post-40,100,40, 45);
                    break;
                case 8:
                    renderTexture(_8,renderer,post-40,100,40, 45);
                    break;
                case 9:
                    renderTexture(_9,renderer,post-40,100,40, 45);
                    break;


                }
                tmp=tmp/10;
                post-=40;
            }
            tmp=record;
            post=1200;
            if(tmp==0) renderTexture(_0,renderer,post-50,50,40,45);
            while(tmp>0)
            {
                int num=tmp%10;
                switch(num)
                {
                case 0:
                    renderTexture(_0,renderer,post-40,50,40, 45);
                    break;
                case 1:
                    renderTexture(_1,renderer,post-40,50,40, 45);
                    break;
                case 2:
                    renderTexture(_2,renderer,post-40,50,40, 45);
                    break;
                case 3:
                    renderTexture(_3,renderer,post-40,50,40, 45);
                    break;
                case 4:
                    renderTexture(_4,renderer,post-40,50,40, 45);
                    break;
                case 5:
                    renderTexture(_5,renderer,post-40,50,40, 45);
                    break;
                case 6:
                    renderTexture(_6,renderer,post-40,50,40, 45);
                    break;
                case 7:
                    renderTexture(_7,renderer,post-40,50,40, 45);
                    break;
                case 8:
                    renderTexture(_8,renderer,post-40,50,40, 45);
                    break;
                case 9:
                    renderTexture(_9,renderer,post-40,50,40, 45);
                    break;
                }
                tmp=tmp/10;
                post-=40;
            }


            switch(x)
            {
            case 225 ... 375:
                button=0;
                renderTexture(red2,renderer,225+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound1, 0 );
                break;
            case 376 ... 525:
                button=1;
                renderTexture(orange2,renderer,225+150*1+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound2, 0 );
                break;
            case 526 ... 675:
                button=2;
                renderTexture(yellow2,renderer,225+150*2+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound3, 0 );
                break;
            case 676 ... 825:
                button=3;
                renderTexture(green2,renderer,225+150*3+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound4, 0 );
                break;
            case 826 ... 975:
                button=4;
                renderTexture(blue2,renderer,225+150*4+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound5, 0 );
                break;

            }


            if(button!=0) renderTexture(red1,renderer,225,SCREEN_HEIGHT/2,150,100);
            if(button!=1)renderTexture(orange1,renderer,225+150*1,SCREEN_HEIGHT/2,150,100);
            if(button!=2)renderTexture(yellow1,renderer,225+150*2,SCREEN_HEIGHT/2,150,100);
            if(button!=3)renderTexture(green1,renderer,225+150*3,SCREEN_HEIGHT/2,150,100);
            if(button!=4)renderTexture(blue1,renderer,225+150*4,SCREEN_HEIGHT/2,150,100);

            if(button==color[0])
            {
                if(color.size()!=0)
                {
                    color.erase(color.begin());
                    score++;
                    if(score>=record) record=score;
                    if(color.size()==0)
                    {
                        int new_= rand()%5;
                        color_master.push_back(new_);
                        Mix_PlayChannel( -1, win_sound, 0 );
                        win=true;
                        stage++;
                        status=3;
                    }
                }

            }
            else
            {
                color_master.erase(color_master.begin(),color_master.end());
                status=99;
                score=0;
                stage=1;
            }
        }

    }



    SDL_RenderPresent(renderer);


}



void refreshScreen4_3( SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *red1,SDL_Texture *red2,
                       SDL_Texture *orange1,SDL_Texture *orange2,SDL_Texture *yellow1,SDL_Texture *yellow2,SDL_Texture *green1,SDL_Texture *green2,
                       SDL_Texture *blue1,SDL_Texture *blue2,SDL_Texture *pink1,SDL_Texture *pink2,SDL_Texture *purple1,SDL_Texture *purple2,SDL_Texture *back_,
                       SDL_Texture *_0,SDL_Texture *_1,SDL_Texture *_2,SDL_Texture *_3,SDL_Texture *_4,SDL_Texture *_5,SDL_Texture *_6,SDL_Texture *_7,
                       SDL_Texture *_8,SDL_Texture *_9,SDL_Texture *score_txt,SDL_Texture *highest_record,SDL_Texture *watch_again,Mix_Chunk *win_sound,Mix_Chunk *sound1, Mix_Chunk *sound2,
                       Mix_Chunk *sound3, Mix_Chunk *sound4, Mix_Chunk *sound5, Mix_Chunk *sound6, Mix_Chunk *sound7,
                       int x,int y,int &status,int &score,int &stage,int &record, vector<int> &color, vector<int> &color_master,const bool mouseDown,bool &win)
{


    if(!mouseDown)
    {

        renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        renderTexture(red1,renderer,75,SCREEN_HEIGHT/2,150,100);
        renderTexture(orange1,renderer,75+150*1,SCREEN_HEIGHT/2,150,100);
        renderTexture(yellow1,renderer,75+150*2,SCREEN_HEIGHT/2,150,100);
        renderTexture(green1,renderer,75+150*3,SCREEN_HEIGHT/2,150,100);
        renderTexture(blue1,renderer,75+150*4,SCREEN_HEIGHT/2,150,100);
        renderTexture(pink1,renderer,75+150*5,SCREEN_HEIGHT/2,150,100);
        renderTexture(purple1,renderer,75+150*6,SCREEN_HEIGHT/2,150,100);
        renderTexture(back_,renderer,20,20,100,30);
        renderTexture(score_txt,renderer,850,100,195,45);
        renderTexture(highest_record,renderer,534,50,520,45);
        renderTexture(watch_again,renderer,475,500,250,45);
        int tmp=score;
        int post=1200;
        if(tmp==0) renderTexture(_0,renderer,post-50,100,40,45);
        while(tmp>0)
        {
            int num=tmp%10;
            switch(num)
            {
            case 0:
                renderTexture(_0,renderer,post-40,100,40, 45);
                break;
            case 1:
                renderTexture(_1,renderer,post-40,100,40, 45);
                break;
            case 2:
                renderTexture(_2,renderer,post-40,100,40, 45);
                break;
            case 3:
                renderTexture(_3,renderer,post-40,100,40, 45);
                break;
            case 4:
                renderTexture(_4,renderer,post-40,100,40, 45);
                break;
            case 5:
                renderTexture(_5,renderer,post-40,100,40, 45);
                break;
            case 6:
                renderTexture(_6,renderer,post-40,100,40, 45);
                break;
            case 7:
                renderTexture(_7,renderer,post-40,100,40, 45);
                break;
            case 8:
                renderTexture(_8,renderer,post-40,100,40, 45);
                break;
            case 9:
                renderTexture(_9,renderer,post-40,100,40, 45);
                break;
            }
            tmp=tmp/10;
            post-=40;
        }
        tmp=record;
        post=1200;
        if(tmp==0) renderTexture(_0,renderer,post-50,50,40,45);
        while(tmp>0)
        {
            int num=tmp%10;
            switch(num)
            {
            case 0:
                renderTexture(_0,renderer,post-40,50,40, 45);
                break;
            case 1:
                renderTexture(_1,renderer,post-40,50,40, 45);
                break;
            case 2:
                renderTexture(_2,renderer,post-40,50,40, 45);
                break;
            case 3:
                renderTexture(_3,renderer,post-40,50,40, 45);
                break;
            case 4:
                renderTexture(_4,renderer,post-40,50,40, 45);
                break;
            case 5:
                renderTexture(_5,renderer,post-40,50,40, 45);
                break;
            case 6:
                renderTexture(_6,renderer,post-40,50,40, 45);
                break;
            case 7:
                renderTexture(_7,renderer,post-40,50,40, 45);
                break;
            case 8:
                renderTexture(_8,renderer,post-40,50,40, 45);
                break;
            case 9:
                renderTexture(_9,renderer,post-40,50,40, 45);
                break;
            }
            tmp=tmp/10;
            post-=40;
        }
    }
    else
    {

        if(x<=120&&y<=50)
        {
            status=1;
        }
        if(475<=x&&x<=725&&500<=y&&y<=545)
        {
            if(score>5)
            {
                score=score-5;
            }
            else score=-1;
            status=3;
        }

        int button;
        if(y<=400&&y>=300&&x>=75&&x<=1125)
        {
            renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
            renderTexture(back_,renderer,20,20,100,30);
            renderTexture(score_txt,renderer,850,100,195,45);
            renderTexture(highest_record,renderer,534,50,520,45);
            renderTexture(watch_again,renderer,475,500,250,45);
            int tmp=score;
            int post=1200;
            if(tmp==0) renderTexture(_0,renderer,post-50,100,40,45);
            while(tmp>0)
            {
                int num=tmp%10;
                switch(num)
                {
                case 0:
                    renderTexture(_0,renderer,post-40,100,40, 45);
                    break;
                case 1:
                    renderTexture(_1,renderer,post-40,100,40, 45);
                    break;
                case 2:
                    renderTexture(_2,renderer,post-40,100,40, 45);
                    break;
                case 3:
                    renderTexture(_3,renderer,post-40,100,40, 45);
                    break;
                case 4:
                    renderTexture(_4,renderer,post-40,100,40, 45);
                    break;
                case 5:
                    renderTexture(_5,renderer,post-40,100,40, 45);
                    break;
                case 6:
                    renderTexture(_6,renderer,post-40,100,40, 45);
                    break;
                case 7:
                    renderTexture(_7,renderer,post-40,100,40, 45);
                    break;
                case 8:
                    renderTexture(_8,renderer,post-40,100,40, 45);
                    break;
                case 9:
                    renderTexture(_9,renderer,post-40,100,40, 45);
                    break;
                }
                tmp=tmp/10;
                post-=40;
            }
            tmp=record;
            post=1200;
            if(tmp==0) renderTexture(_0,renderer,post-50,50,40,45);
            while(tmp>0)
            {
                int num=tmp%10;
                switch(num)
                {
                case 0:
                    renderTexture(_0,renderer,post-40,50,40, 45);
                    break;
                case 1:
                    renderTexture(_1,renderer,post-40,50,40, 45);
                    break;
                case 2:
                    renderTexture(_2,renderer,post-40,50,40, 45);
                    break;
                case 3:
                    renderTexture(_3,renderer,post-40,50,40, 45);
                    break;
                case 4:
                    renderTexture(_4,renderer,post-40,50,40, 45);
                    break;
                case 5:
                    renderTexture(_5,renderer,post-40,50,40, 45);
                    break;
                case 6:
                    renderTexture(_6,renderer,post-40,50,40, 45);
                    break;
                case 7:
                    renderTexture(_7,renderer,post-40,50,40, 45);
                    break;
                case 8:
                    renderTexture(_8,renderer,post-40,50,40, 45);
                    break;
                case 9:
                    renderTexture(_9,renderer,post-40,50,40, 45);
                    break;
                }
                tmp=tmp/10;
                post-=40;
            }

            switch(x)
            {
            case 75 ... 225:
                button=0;
                renderTexture(red2,renderer,75+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound1, 0 );
                break;
            case 226 ... 375:
                button=1;
                renderTexture(orange2,renderer,75+150*1+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound2, 0 );
                break;
            case 376 ... 525:
                button=2;
                renderTexture(yellow2,renderer,75+150*2+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound3, 0 );
                break;
            case 526 ... 675:
                button=3;
                renderTexture(green2,renderer,75+150*3+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound4, 0 );
                break;
            case 676 ... 825:
                button=4;
                renderTexture(blue2,renderer,75+150*4+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound5, 0 );
                break;
            case 826 ... 975:
                button=5;
                renderTexture(pink2,renderer,75+150*5+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound6, 0 );
                break;
            case 976 ... 1125:
                button=6;
                renderTexture(purple2,renderer,75+150*6+2,SCREEN_HEIGHT/2+2,146,96);
                Mix_PlayChannel( -1, sound7, 0 );
                break;
            }
            if(button!=0) renderTexture(red1,renderer,75,SCREEN_HEIGHT/2,150,100);
            if(button!=1)renderTexture(orange1,renderer,75+150*1,SCREEN_HEIGHT/2,150,100);
            if(button!=2)renderTexture(yellow1,renderer,75+150*2,SCREEN_HEIGHT/2,150,100);
            if(button!=3)renderTexture(green1,renderer,75+150*3,SCREEN_HEIGHT/2,150,100);
            if(button!=4)renderTexture(blue1,renderer,75+150*4,SCREEN_HEIGHT/2,150,100);
            if(button!=5)renderTexture(pink1,renderer,75+150*5,SCREEN_HEIGHT/2,150,100);
            if(button!=6)renderTexture(purple1,renderer,75+150*6,SCREEN_HEIGHT/2,150,100);


            if(button==color[0])
            {
                if(color.size()!=0)
                {
                    color.erase(color.begin());
                    score++;
                    if(score>=record) record=score;
                    if(color.size()==0)
                    {
                        int new_= rand()%7;
                        color_master.push_back(new_);
                        Mix_PlayChannel( -1, win_sound, 0 );
                        win=true;
                        stage++;
                        status=3;
                    }
                }

            }
            else
            {
                color_master.erase(color_master.begin(),color_master.end());
                status=99;
                score=0;
                stage=1;
            }
        }

    }
    SDL_RenderPresent(renderer);


}
void refreshScreenOver(SDL_Renderer* renderer,SDL_Texture *background,SDL_Texture *gameOver,SDL_Texture *play_again,SDL_Texture *menu, int x, int y,
                       int &status, const bool mouseDown)
{

    if(!mouseDown)
    {
        renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        renderTexture(gameOver,renderer,325,200,550,70);
        renderTexture(play_again,renderer,495,400,210,30);
        renderTexture(menu,renderer,460,435,280,30);
        SDL_RenderPresent(renderer);

    }
    else
    {

        if(495<=x&&x<=705&&400<=y&&y<=430)
        {
            status=3;
        }
        if(460<=x&&x<=740&&435<=y&&y<=465)
        {
            status=1;
        }
    }

}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren)
{

    SDL_Texture *texture = nullptr;
    SDL_Surface *loadedImage = IMG_Load(file.c_str());
    if (loadedImage != nullptr)
    {
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        if (texture == nullptr)
        {
            logSDLError(std::cout, "CreateTextureFromSurface");
        }
    }
    else
    {
        logSDLError(std::cout, file);
    }
    return texture;
}



void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true)
    {
        if ( SDL_WaitEvent(&e) != 0 &&
                (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}


