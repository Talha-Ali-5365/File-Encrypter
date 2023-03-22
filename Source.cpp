#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
using namespace sf;
int int_len(int n)
{
	int a=0;
	while(n>0)
	{
		n/=10;
		a++;
	}
	return a;
}
int main()
{
    RenderWindow app(sf::VideoMode(700, 400), "Encrypt");
    app.setFramerateLimit(60);
    Texture t1,t2,t3,t4;
    Font myfont;
        //error handling if font file is unable to load
    if (!myfont.loadFromFile("arial.ttf"))
    {
        cout<<"Error Loading fonts!"<<endl;
    }
    sf::String test,test2,test3;
    Vector2i pos;
    sf::Text text0("FILE ENCRYPTION SYSTEM",myfont,25);
    sf::Text text("Enter file name and extension",myfont,18);
    sf::Text text2("|",myfont,15);
    sf::Text text3("|Encrypt|\n\n|Decrypt|",myfont,30);
    sf::Text text4("Key",myfont,20);
    sf::Text text5(" ",myfont,25);
    sf::Text text6("|",myfont,15);
    sf::Text text7("Output file-name",myfont,20);
    sf::Text text8("|",myfont,15);
    sf::Text text9("Created by:\n  Talha Ali",myfont,15);
    sf::Text text10("T\n\n\nT\n\n\nT",myfont,35);
    text0.setFillColor(Color::Yellow);
    text.setFillColor(Color::Yellow);
    text2.setFillColor(Color::Black);
    text3.setFillColor(Color::Yellow);
    text4.setFillColor(Color::Yellow);
    text5.setFillColor(Color::Yellow);
    text6.setFillColor(Color::Black);
    text7.setFillColor(Color::Yellow);
    text8.setFillColor(Color::Black);
    text9.setFillColor(Color::Yellow);
    text10.setFillColor(Color::Black);
    text0.setPosition(30,20);
	text.setPosition(175,105);
    text4.setPosition(175,210);
    text7.setPosition(175,310);
    text3.setPosition(530,172);
    t1.loadFromFile(".\\e6.jpg");
    t2.loadFromFile(".\\t3.png");
    t3.loadFromFile(".\\t3.png");
    t4.loadFromFile(".\\t3.png");
    Sprite back(t1),box(t2),box2(t3),box3(t4);
    box.setPosition(5,75);
    box2.setPosition(5,180);
    box3.setPosition(5,285);
    text2.setPosition(120,145);
    text6.setPosition(120,250);
    text8.setPosition(120,355);
    text9.setPosition(600,20);
    text10.setPosition(60,100);
    app.draw(text2);
    int key=0,flag=0;
    char ch,ch2;
    string fname="",oname="";
    ifstream in;
	ofstream out;
    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            if(event.type==sf::Event::TextEntered)
            {
            	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab))
            	{
            		if(flag==2)
            			flag=0;
					else
						flag++;
				}
            	if(flag==0)
            	{
            		if(fname.length()<25)
            		{
            			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace))
		            	{
		            		test="";
		            		fname="";
						}
						else
						{
		            		test=test+event.text.unicode;
			            	fname+=event.text.unicode;
			            }
		            	text2.setString(test);
		            }
	            }
	            else if(flag==1)
	            {
	            	if(int_len(key)<10)
	            	{
	            		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace))
		            	{
		            		test2="";
		            		key=0;
						}
						else
						{
				            test2+=event.text.unicode;
				            key=(key*10)+(((int)(event.text.unicode))-48);
				        }
			            text6.setString(test2);
			        }
		        }
		        else if(flag==2)
            	{
            		if(oname.length()<25)
            		{
            			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace))
		            	{
		            		test3="";
		            		oname="";
						}
						else
						{
		            		test3+=event.text.unicode;
			            	oname+=event.text.unicode;
			            }
		            	text8.setString(test3);
		            }
	            }
			}
			if(event.type == sf::Event::MouseButtonPressed)
            {
                    //check if pressed button is Left-click
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                            //storing mouse position is Vector variable
                            pos=Mouse::getPosition(app);
                            //339-401x 429-491    196-208y    
                            
                            if((pos.x>=534 && pos.x<=645) && (pos.y>=178 && pos.y<=202))
					        {
								in.open(fname,ios::binary);
								out.open(oname,ios::binary);
								while(!in.eof())
								{
									in>>noskipws>>ch;
									out<<(char)(ch+key);
								}
								text5.setString("File Encrypted Successfully!");
								text5.setPosition(370,350);
								in.close();
								out.close();
							}
							else if((pos.x>=534 && pos.x<=645) && (pos.y>=249 && pos.y<=272))
					        {
								in.open(fname,ios::binary);
								out.open(oname,ios::binary);
								while(!in.eof())
								{
									in>>noskipws>>ch;
									out<<(char)(ch-key);
								}
								text5.setString("File Decrypted Successfully!");
								text5.setPosition(370,350);
								app.draw(text5);
								in.close();
								out.close();
							}
							if((pos.x>=120 && pos.x<=311) && (pos.y>=240 && pos.y<=279))
							{
								flag=1;
							}
							else if((pos.x>=119 && pos.x<=313) && (pos.y>=131 && pos.y<=173))
							{
								flag=0;
							}
							else if((pos.x>=119 && pos.x<=313) && (pos.y>=342 && pos.y<=385))
							{
								flag=2;
							}
							//text.setString(to_string(pos.y));
                    }
            }
        }
//120-311x     240-279
		//text.setString(to_string(key));
        app.clear();
        app.draw(back);
        app.draw(box);
        app.draw(box2);
        app.draw(box3);
        app.draw(text0);
		app.draw(text);
        app.draw(text2);
        app.draw(text3);
        app.draw(text4);
        app.draw(text5);
        app.draw(text6);
        app.draw(text7);
        app.draw(text8);
        app.draw(text9);
        app.draw(text10);
		app.display();
    }

    return 0;
}
