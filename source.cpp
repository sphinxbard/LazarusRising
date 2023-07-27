			//Lazarus Rising- an RPG

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#define defeat cout<<"You lose a life. Start again";currentplayer.lives--;wannaexit();
#define stddisplay clrscr();life(currentplayer.lives);displaylevelno(currentlevelno);
int flag;
int currentlevelno,currenttaskno;
void main(char input='n');
char * enterpassword()
{
	char a,Password[40];
	//Enter the password:
	for(int i=0;i>=0;)
	{
		a=getch();
		if(a!=8&&a!=13)	//if a is neither backspace nor enter
		{
			Password[i]=a;
			cout<<"*";
			i++;
		}
		else if(a==8)	//if a is backspace
		{
			cout<<"\b \b";
			i--;
		}
		else if(a==13)	//if a is enter
		{
			Password[i]='\0';
			break;
		}
	}
	return Password;
}

class player
{
	char password[40],email_id[40];
	public:
	char name[30],city[20];
	int age,lives,savelevelno,savetaskno;
	player()
	{
		lives=3;
	}
	void operator=(const player &p)
	{
		strcpy(name,p.name);
		strcpy(password,p.password);
		lives=p.lives;
		savelevelno=p.savelevelno;
		savetaskno=p.savetaskno;
	}
	void enterdetails()
	{
		cout<<"What would you like us to call you? \n";
		gets(name);
		cout<<"Enter your E-mail id: ";
		gets(email_id);
		cout<<"Enter your age: ";
		cin>>age;
		cout<<"Tell us which city you live in: ";
		gets(city);
		cout<<"Create a unique password for yourself: \n";
		strcpy(password,enterpassword());
		cout<<name<<", your profile is successfully created. ";
		getch();
		clrscr();
	}
	void show()
	{
		cout<<"\n Name: "<<name;
		cout<<"\n Age: "<<age;
		cout<<"\n E-mail Id: "<<email_id;
		cout<<"\n City: "<<city;
		cout<<"\n Password: "<<password;
		cout<<"\n Lives: "<<lives;
		cout<<"\n Saved level no.: "<<savelevelno;
		cout<<"\n Saved task no.: "<<savetaskno<<endl;
	}
	char * retpassword()
	{
		return password;
	}
	void Changepassword(char * newpassword)
	{
		strcpy(password,newpassword);
	}
};
player currentplayer;
void wannaexit()
{
	int c=getch();
	if(c=='!'||currentlevelno==11) //also saves the progress if the player
	{                          //has finished the game and doesn't press !
		currentplayer.savelevelno=currentlevelno;
		currentplayer.savetaskno=currenttaskno;
		//now modify current player's record in players.dat file
		fstream f("players.dat",ios::in|ios::out|ios::binary);
		player p1;
		while(!f.eof())
		{
			long pos=f.tellg();
			f.read((char*)&p1,sizeof(p1));
			if(strcmpi(p1.name,currentplayer.name)==0)
			{
				p1=currentplayer;
				f.seekg(pos);
				f.write((char*)&p1,sizeof(p1));
				break;
			}
		}
		f.seekg(0);
		f.close();
		if(currentlevelno!=11)
			exit(1);
	}//closing bracket of if(c=='!')
}
void level1();
void level2();
void level3(int taskno=1);
void level4(int taskno=1);
void level5(int taskno=1);
void level6(int taskno=1);
void level7();
void level8(int taskno=1);
void level9(int taskno=1);
void level10(int taskno=1);
void continuegame(int sln,int stn)
{
	if(sln==1)
		level1();
	else if(sln==2)
		level2();
	else if(sln==3)
		level3(stn);
	else if(sln==4)
		level4(stn);
	else if(sln==5)
		level5(stn);
	else if(sln==6)
		level6(stn);
	else if(sln==7)
		level7();
	else if(sln==8)
		level8(stn);
	else if(sln==9)
		level9(stn);
	else if(sln==10)
		level10(stn);
	else if(sln==11)
	{
		clrscr();
		char yesno;
		cout<<currentplayer.name<<", you've already saved humanity from Lazarus. \n";
		cout<<"Would you like to play another game?(y/n)";
		cin>>yesno;
		clrscr();
		if(yesno=='y'||yesno=='Y')
		{
			currentplayer.lives=3;
			main('s');
		}
		else
			main();
	}
}

void celebrationsound()
{
	sound(300);
	delay(300);
	sound(350);
	delay(300);

	sound(400);
	delay(100);
	sound(500);
	delay(100);
	sound(700);
	delay(100);

	sound(400);
	delay(100);
	sound(500);
	delay(100);
	sound(700);
	delay(100);

	sound(400);
	delay(100);
	sound(500);
	delay(100);
	sound(700);
	delay(100);

	sound(900);
	delay(300);
	nosound();
}

void levelupsound()
{
	sound(300);
	delay(100);
	sound(500);
	delay(100);
	sound(700);
	delay(300);
	nosound();
}
void rightsound()
{
		sound(300);
		delay(100);
		sound(550);
		delay(300);
		nosound();
}
void wrongsound()
{
		sound(200);
		delay(500);
		nosound();

}
void life(int &lives)
{
	char heart=3;
	if(lives==4)
		cout<<"\t\t\t\t\t\t\t\t\t    "<<heart<<heart<<heart<<heart<<endl;
	else if(lives==3)
		cout<<"\t\t\t\t\t\t\t\t\t    "<<heart<<heart<<heart<<endl;
	else if(lives==2)
		cout<<"\t\t\t\t\t\t\t\t\t    "<<heart<<heart<<endl;
	else if(lives==1)
		cout<<"\t\t\t\t\t\t\t\t\t    "<<heart<<endl;
	else
	{
		currentplayer.lives=3;
		if(currentlevelno!=1)
			main('o');
		else
			return;
	}
}
void displaylevelno(int levelno)
{
	if(levelno==1)
		cout<<endl<<"\t\t\t\t\t\t\t\t    "<<"Level 1";
	else if(levelno==2)
		cout<<endl<<"\t\t\t\t\t\t\t\t    "<<"Level 2";
	else if(levelno==3)
		cout<<endl<<"\t\t\t\t\t\t\t\t    "<<"Level 3";
	else if(levelno==4)
		cout<<endl<<"\t\t\t\t\t\t\t\t    "<<"Level 4";
	else if(levelno==5)
		cout<<endl<<"\t\t\t\t\t\t\t\t    "<<"Level 5";
	else if(levelno==6)
		cout<<endl<<"\t\t\t\t\t\t\t\t    "<<"Level 6";
	else if(levelno==7)
		cout<<endl<<"\t\t\t\t\t\t\t\t    "<<"Level 7";
	else if(levelno==8)
		cout<<endl<<"\t\t\t\t\t\t\t\t    "<<"Level 8";
	else if(levelno==9)
		cout<<endl<<"\t\t\t\t\t\t\t\t    "<<"Level 9";
	else if(levelno==10)
		cout<<endl<<"\t\t\t\t\t\t\t\t    "<<"Level 10";
}

void createprofile()
{
	ifstream fin;
	ofstream fout;
	fin.open("players.dat",ios::binary);
	fout.open("players.dat",ios::binary|ios::app);
	player p1,p2;//p2 is for reading
	p1.enterdetails();
	while(fin.read((char *)&p2,sizeof(p2)))//loop checks existing file to
	{                                    //prevent username doubling
		while(strcmpi(p2.name,p1.name)==0)//inner loop does not allow
		{                                  /*user to enter the same
						   rejected name over
						   and over again*/
			cout<<"Sorry, name already taken. Please choose another username.\n";
			gets(p1.name);
		}
	}
	fout.write((char *)&p1,sizeof(p1));
	fin.close();
	fout.close();
	currentplayer=p1;
	main('s');//start the game by displaying the story
}
void openprofile()
{
	ifstream fin("players.dat",ios::binary);
	char Name[30],Password[40];
	int found=0,count=0;
	player p1;
	cout<<"Enter your name: ";
	gets(Name);
	while(fin.read((char*)&p1,sizeof(p1)))
	{
		if(strcmpi(Name,p1.name)==0)
		{
			found=1;
 Enterpassword:         cout<<"\n Enter your password: ";
			strcpy(Password,enterpassword());
			if(strcmp(Password,p1.retpassword())==0)
			{
				currentplayer=p1;
				continuegame(currentplayer.savelevelno,currentplayer.savetaskno);
				//continue game from last saved
				break;
			}
			else if(count<3)
			{
				count++;
				wrongsound();
				cout<<"\nWrong password.\n";
				goto Enterpassword;
			}
			else
			{
				wrongsound();
				cout<<"\nToo many failed attempts! Exiting...";
				getch();
				exit(1);
			}
		}//closing bracket of if(comparing name)
	} //closing bracket of while(reading) loop
	if(!found)
	{
		char choice;
		cout<<"Player not found. Would you like to create a new profile?(y/n) \n";
		cin>>choice;
		if(choice=='y'||choice=='Y')
			createprofile();
		else
			main();
	}
	fin.close();
}
void changepassword()
{
	fstream f("players.dat",ios::binary|ios::in|ios::out);
	player p1;
	char name[30];
	int found=0;
	cout<<"Enter your name: ";
	gets(name);
	while(!f.eof())
	{
		long pos=f.tellg();
		f.read((char *)&p1,sizeof(p1));
		if(strcmpi(name,p1.name)==0)
		{
			found=1;
			char oldpassword[40];
			cout<<"Enter your old password: ";
			strcpy(oldpassword,enterpassword());
			if(strcmp(oldpassword,p1.retpassword())==0)
			{
				char newpassword[40];
				cout<<"\n Create new password: ";
				strcpy(newpassword,enterpassword());
				p1.Changepassword(newpassword);
				f.seekg(pos);
				f.write((char *)&p1,sizeof(p1));
				cout<<"Change successful. ";
				getch();
				break;
			}
			else
			{
				cout<<"Passwords do not match. Redirecting to main menu... ";
				getch();
				main();
			}
		}
	}
	if(!found)
	{
		cout<<"Profile not found! Redirecting to main menu... ";
		getch();
		main();
	}
	f.close();
	main();
}
void deleteprofile()
{
	ifstream fin("players.dat",ios::binary);
	ofstream fout("temp.dat",ios::binary);
	player p1;
	char name[30],password[40];
	int found=0,deleted=0;
	cout<<"Enter your name: ";
	gets(name);
	while(fin.read((char *)&p1,sizeof(p1)))
	{
		if(strcmpi(name,p1.name)==0)
		{
			found=1;
			int confirm=0;
			cout<<"Enter your password: ";
			strcpy(password,enterpassword());
			if(strcmp(password,p1.retpassword())==0)
			{
				cout<<endl<<p1.name<<", are you sure you want to delete your profile? Press 1 to confirm and 0 to decline: ";
				cin>>confirm;
				if(!confirm)
					fout.write((char *)&p1,sizeof(p1));
				else
					deleted=1;
			}
			else
			{
				cout<<"Passwords do not match! Redirecting to main menu...";
				getch();
				main();
			}
		}
		else
			fout.write((char *)&p1,sizeof(p1));
	}
	if(!found)
		cout<<"Sorry, profile not found";
	if(deleted)
	{
		cout<<"Deletion successful.";
		getch();
	}
	fin.close();
	fout.close();
	remove("players.dat");
	rename("temp.dat","players.dat");
	main();
}
//functions for developer menu
void showallprofiles();
void showbyage();
void showbycity();
void deleteall()
{
	fstream f("players.dat",ios::binary);
	f.close();
	remove("players.dat");
	cout<<"All profiles successfully deleted. ";
}
void developermenu()
{
	int option;
	char choice;
	do
	{
		clrscr();
		cout<<"What would you like to do? \n";
		cout<<"1.View details of all players \n";
		cout<<"2.Show age statistics \n";
		cout<<"3.Show city statistics \n";
		cout<<"4.Go back to main menu \n";
		cout<<"5.Exit \n";
		cin>>option;
		switch(option)
		{
			case 1: showallprofiles();break;
			case 2: showbyage();break;
			case 3: showbycity();break;
			case 4: main();break;
			case 5: exit(1);
			case 42: deleteall();break;
			default: cout<<"Wrong option.Choose again. ";
		}
		cout<<"\n Do you want to continue?(y/n) \n";
		cin>>choice;
	}while(choice=='y'||choice=='Y');
}
void showallprofiles()
{
	ifstream fin;
	fin.open("players.dat",ios::binary);
	player p1;
	clrscr();
	while(fin.read((char *)&p1,sizeof(p1)))
	{
		p1.show();
		cout<<endl;
	}
	fin.close();
}
void showbyage()
{
	ifstream fin("players.dat",ios::binary);
	player p1;
	int upperage,lowerage,count=0,totalno=0;
	do
	{
		cout<<"Enter the lower limit of the age range: ";
		cin>>lowerage;
		cout<<"Enter the upper limit of the age range: ";
		cin>>upperage;
	}while(lowerage>upperage);
	clrscr();
	while(fin.read((char *)&p1,sizeof(p1)))
	{
		totalno++;
		if(p1.age>=lowerage&&p1.age<=upperage)
		{
			p1.show();
			cout<<endl;
			count++;
		}
	}
	float percentage=((float)count/float(totalno))*100;
	cout<<"\n Total no. of players registered: "<<totalno;
	cout<<"\n Total no. of players in age range "<<lowerage<<"-"<<upperage<<": "<<count;
	cout<<"\n Percentage of players in age range "<<lowerage<<"-"<<upperage<<": "<<percentage<<"%";
	getch();
	fin.close();
}
void showbycity()
{
	ifstream fin("players.dat",ios::binary);
	player p1;
	int count=0,totalno=0;
	char city[20];
	cout<<"Enter the city: ";
	gets(city);
	clrscr();
	while(fin.read((char *)&p1,sizeof(p1)))
	{
		if(strcmpi(city,p1.city)==0)
		{
			p1.show();
			cout<<endl;
			count++;
		}
	}
	float percentage=((float)count/float(totalno))*100;
	cout<<"\n Total no. of players registered: "<<totalno;
	cout<<"\n Total no. of players in "<<city<<": "<<count;
	cout<<"\n Percentage of players in "<<city<<": "<<percentage<<"%";
	fin.close();
}
//developer menu functions end, levels begin
void level1()
{
	currentlevelno=1;
	char rightans[]="Echo",answer[10];
	stddisplay;
	cout<<endl<<"For your first task, the two-headed snake at the base of the mountain asks you a riddle:";
	cout<<endl<<"I speak without a mouth and hear without ears. I have no body but";
	cout<<" I come alive with the wind. What am I?";
	cout<<endl<<"Answer in one word ";
	wannaexit();
	gets(answer);
	if(strcmpi(answer,rightans)==0)
	{
		levelupsound();
		cout<<"Well played, champion. You may move ahead.";
		flag=1;
		wannaexit();
	}
	else
	{
		wrongsound();
		cout<<"That is the wrong answer. The snakes have the honour of feasting on you.\n";
		flag=0;
		defeat;
	}

}

void level2()
{
	currentlevelno=2;
	int option;
	stddisplay;
	cout<<endl<<"You next meet one of Lazarus' henchmen, who's also an assistant chemist to him. He holds a bottle of water and asks you a question-";
	cout<<"'This bottle containing water at room temperature is carried in a spaceship and then placed upon the surface of the dark side of the moon. What will happen to the bottle's water when the cap is opened? I will give you 4 options:";
	cout<<"1. It will freeze and remain as ice.";
	cout<<endl<<"2. It will boil, then form a solid.";
	cout<<endl<<"3. It will boil and remain as a vapor.";
	cout<<endl<<"4. It will decompose into Hydrogen and Oxygen molecules. \n";
	cout<<"Think and choose carefully, or I will blast you with my hydrochloric acid gun,' he says.";
	cout<<"What's the correct answer? (Type the option number- 1,2,3 or 4) ";
	wannaexit();
	cin>>option;
	if(option==2)
	{
		levelupsound();
		cout<<"That's right! The chemist has no choice but to let you pass to the next level.";
		flag=2;
		wannaexit();
	}
	else
	{
		wrongsound();
		cout<<"That's wrong. The right answer is 2, because in vacuum, there's no outside pressure, so the vapour pressure of water will match the outside pressure, and it will boil. But it is extremely cold on the dark side of the moon, so immediately after boiling, it will freeze.";
		flag=0;
		defeat;
	}

}

void level3(int taskno)
{
	currentlevelno=3;
	int i,j,score=0;	//for task 1-anagrams
	char word1_anagrams[4][9]={"altering","integral","relating","triangle"}; //alerting
	char word2_anagrams[2][10]={"auctioned","cautioned"}; //education
	char word3_anagrams[2][10]={"liberates","beastlier"}; //bleariest
	if(taskno==1)
		goto l3task1;
	else if(taskno==2)
		goto l3task2;
	l3task1:
	currenttaskno=1;
	char Word1_anagrams[4][9],Word2_anagrams[2][10],Word3_anagrams[2][10];
	stddisplay;
	cout<<endl<<"Your next enemy is the Wordsmith. You see him working at his forge of words, creating new vocabulary to enlighten the world with.";
	cout<<"(Ah, yes. His presence is quite infectious, you see). The Wordsmith loves all kinds of word games, but he has a soft spot for anagrams.";
	cout<<"He'll only allow you to pass if you make two anagrams each of the two words he gives you.";
	cout<<"But because he loves anagrams so much, he'll give you a bonus word as well, which has four anagrams excluding itself. If you get any two, well and good.";
	cout<<"But if you get all four, you'll get a special prize from him- one life. Otherwise, he'll just allow you to pass and also free Syvian-the elf he's imprisoned with a fiery Thesaurus to guard him.";
	cout<<"If you manage to free him, Syvian the elf will accompany you from now on. He's a loyal partner, and you'll learn more about him as you travel with him. But, for now, tackle the Wordsmith. \n";
	cout<<"Your first word is: education \n Type out its two possible anagrams(apart from itself) one by one ";
	wannaexit();
	gets(Word2_anagrams[0]);
	gets(Word2_anagrams[1]);
	for(i=0;i<2;i++)
	{
		if(strcmpi(Word2_anagrams[i],word2_anagrams[0])==0||strcmpi(Word2_anagrams[i],word2_anagrams[1])==0)
			score++;  //if input anagram matches any element of statically initialised 2-d string array, score++
	}
	wannaexit();
	cout<<"\n Your second word is: bleariest \n Type out its two possible anagrams(apart from itself) one by one ";
	wannaexit();
	gets(Word3_anagrams[0]);
	gets(Word3_anagrams[1]);
	for(i=0;i<2;i++)     //same thing as done for 'education'
	{
		if(strcmpi(Word3_anagrams[i],word3_anagrams[0])==0||strcmpi(Word3_anagrams[i],word3_anagrams[1])==0)
			score++;  //if input anagram matches any element of statically initialised 2-d string array, score++
	}
	wannaexit();
	cout<<"\n Now it's time for the bonus word! The word is: alerting. Type out at least two of its anagrams.";
	cout<<"If you're unable to get more than two, just press enter twice. Otherwise keep going until four.";
	wannaexit();
	gets(Word1_anagrams[0]);
	gets(Word1_anagrams[1]);
	gets(Word1_anagrams[2]);
	gets(Word1_anagrams[3]);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(strcmpi(Word1_anagrams[i],word1_anagrams[j])==0)
				score++;
		}
	}
	if(score==8)
	{
		currentplayer.lives++;
		rightsound();
		cout<<"Brilliant! You're a word-wide wonder. The Wordsmith is pleased. He frees Syvian to accompany you, and also gives you your special reward- a life.";
		flag=1;
		wannaexit();
	}
	else if(score==6)
	{
		flag=1;
		rightsound();
		cout<<"Very well played! The Wordsmith frees Syvian and lets you pass.";
		wannaexit();
	}
	else
	{
		flag=0;
		wrongsound();
		cout<<" 'Apologies, fine wanderer,' the Wordsmith says. 'I cannot let you pass. Perhaps you would do well to start from square one.";
		defeat;
	}

	if(flag==1) //enters 2nd task only if 1st task is completed
	{
		l3task2:
		currenttaskno=2;
		stddisplay;
		int reply,angle;
		cout<<endl<<"'Hello, "<<currentplayer.name;
		cout<<". I'm very grateful to you for freeing me. That Thesaurus used to torture me all day with his incomprehensible vocabulary. Thank you so much.'";
		cout<<" \n Reply to Syvian(press a number): \n 1.'Don't mention it, buddy. Thesauruses- ugh. Or is it Thesauri? I dunno. How'd you end up here anyway?' \n";
		cout<<" 2.'You're very welcome, partner. So what're we supposed to do next?' \n 3.'It is my pleasure and honour. I'm very excited to meet a real elf. What kind of powers do you have?'";
		wannaexit();
		cin>>reply;
		if(reply==1)
		{
			cout<<" 'Haha. Maybe we should go back and ask the Thesaurus itself. Us elfs are known for tinkering and stuff, you know. So Lazarus basically kidnapped me from the forest to work on his Dehumaniser. But I didn't want to. Humans are nice. He was gonna make them not-nice, and that didn't go down well with me. So I escaped from his fortress, but my freedom was short-lived. The Wordsmith captured me and, as they say, the rest is history.' ";
			wannaexit();
		}
		else if(reply==2)
		{
			cout<<"Syvian looks up at the sky. 'In a short while the bomber drone will be above us. There's no way to escape it except to destroy it first, so we need to get to the dronegun as quickly as possible. I'll lead the way.' ";
			wannaexit();
		}
		else if(reply==3)
		{
			cout<<" 'Honoured to meet you too, saviour of humanity. I'm good with making things, and I'm fast, I guess.' Syvian smiles shyly. 'And I have a very cool bow and arrow, not to mention pointy ears,' he draws out his arrow from his quiver and you both laugh. 'And oh, I can know everything about something by looking at it. And I can see you're the perfect Achilles' heel for Lazarus.' ";
			wannaexit();
		}
		else
			cout<<"'Apparently you don't want to talk. So let's get down to business, then.' \n ";
		wannaexit();
		if(reply!=2&&(reply==1||reply==3))
		{
			cout<<"Syvian looks up at the sky. 'I'd love to talk more, but in a short while the bomber drone will be above us. There's no way to escape it except to destroy it first, so we need to get to the dronegun as quickly as possible. I'll lead the way.' ";
			getch();
		}
		else if(reply!=2&&reply!=1&&reply!=3)
		{
			cout<<"Syvian looks up at the sky. 'In a short while the bomber drone will be above us. There's no way to escape it except to destroy it first, so we need to get to the dronegun as quickly as possible. I'll lead the way.' ";
			getch();
		}
		clrscr();
		stddisplay;
		cout<<"\n Syvian leads you to a shiny black metal cannon with a protractor mounted on it. He looks at it carefully. 'Its muzzle speed is 600 m/s', he says.";
		wannaexit();
		if(reply!=3)
			cout<<"You're baffled. 'How'd you know that?' you ask. Syvian grins. 'Oh, just one of my powers. I can know everything about something just by looking at it.' ";
		cout<<"Soon, you see the bomber drone, a mere point in the sky. Syvian concentrates hard upon it. 'It's flying at 720 km/h and 1.5 km above the ground.' You look admiringly at your new friend. 'Soon, it's gonna pass directly overhead. Maths is one of my weaknesses, you see, so you'll have to figure out how to hit it.' He frowns. \n At what angle should you fire the cannon so that it destroys the drone when it's directly above the cannon? Type an integral value for the angle in degrees: ";
		wannaexit();
		cin>>angle;
		if(angle==19||angle==20)
		{
			flag=3;
			levelupsound();
			cout<<"The shell hits the drone spot on. Now it's Syvian's turn to look at you admiringly. 'My god you're good at maths.' In high spirits, the two of you move ahead to level 4.";
			cout<<"Also, congratulations! You've just passed a checkpoint, which means the next time you lose a life, you'll start from level 4, not level 1.";
			wannaexit();
		}
		else
		{
			flag=0;
			wrongsound();
			cout<<"Your calculations fail and the bomb drops right on top of you.";
			defeat;
		}
	}
	/*else doesn't enter 2nd task
	goes back to calling statement in main and enters level 1*/

}

void level4(int taskno)
{
	currentlevelno=4;
	if(taskno==1)
		goto l4task1;
	else
		goto l4task2;
	l4task1:
	int choice;    //1st task
	currenttaskno=1;
	stddisplay;
	cout<<endl<<"You're a contestant of a deadly game show hosted by one of Loki's best apprentices. There are 10 closed doors: 9 lead to fire-breathing giants and 1 leads to Excalibur, the legendary sword. You are allowed to pick a door and earn the sword if it's behind the door you choose. \n";
	cout<<"Stage 1: You choose a door. \n";
	cout<<"Stage 2: The host tells you to choose from two helpful options: \n";
	cout<<"Option 1: Open Five doors! \n";
	cout<<"\t You choose four more doors in addition to the one you've already selected and open all 5. You win the sword if it is behind any of the five doors you choose and open. \n";
	cout<<"Option 2: The host eliminates 8 red herrings! \n";
	cout<<"\t The host will open 8 empty doors that are not the door you chose initially that do not contain the sword, and neutralise the giants behind them. This leaves two doors closed: your initial choice and one other door -- the sword is definitely behind one of them. You can then choose to either open the original door you chose in stage 1 or open the only other remaining closed door. \n";
	cout<<"What should you do to maximize your chances of winning the sword?(enter a number) \n 1.Choose option 1 \n 2. Choose option 2 \n 3. You should be indifferent \n";
	wannaexit();
	cin>>choice;
	int a;
	if(choice==2)
	{
		flag=1;
		rightsound();
		cout<<"That's right! Your reasoning wins you the Excalibur and Syvian takes pleasure in taunting the host. \n";
		cout<<"If you want to view the explanation for the answer, press 1. Otherwise, press any other number. \n";
		wannaexit();
		cin>>a;
		if(a==1)
		{
			cout<<"If you take option 1, then you have 5 chances in 10 to get the sword, for a probability of 5/10=1/2 of success. \n";
			cout<<"If you take option 2 and switch to the door you did not choose initially, then you can do much better than a 1/2 of success.";
			cout<<"Observe that there is only a 1/10 probability that the sword is behind the first door you choose.";
			cout<<"When the host opens 8 empty doors, that rules out each of those 8 doors - but it does not make your initial door any more likely, since the host guaranteed to open 8 empty doors.";
			cout<<"In other words, he added no new information. Thus, the one door that you did not choose and that the host did not open has a 9/10 chance of having the sword behind it.\n";
			cout<<"Therefore, choose option 2 and then switch to open door you did not initially choose, and you will win the sword on this game show 9/10ths of the time!";
			wannaexit();
		}
	}
	else
	{
		wrongsound();
		flag=3;
		cout<<"That is incorrect. The fiery giant burns you to a crisp and you lose this game show.";
		cout<<"\nIf you want to view the explanation for the answer, press 1. Otherwise, press any other number. \n";
		wannaexit();
		cin>>a;
		if(a==1)
		{
		cout<<"\n \n Explanation: \n";
		cout<<"If you take option 1, then you have 5 chances in 10 to get the , for a probability of 5/10=1/2 of success. \n";
		cout<<"If you take option 2 and switch to the door you did not choose initially, then you can do much better than a 1/2 of success.";
		cout<<"Observe that there is only a 1/10 probability that the sword is behind the first door you choose.";
		cout<<"When the host opens 8 empty doors, that rules out each of those 8 doors - but it does not make your initial door any more likely, since the host guaranteed to open 8 empty doors.";
		cout<<"In other words, he added no new information. Thus, the one door that you did not choose and that the host did not open has a 9/10 chance of having the sword behind it.\n";
		cout<<"Therefore, choose option 2 and then switch to open door you did not initially choose, and you will win the sword on this game show 9/10ths of the time!";
		cout<<endl;
		}
		defeat;
	}

	if(flag==1) //if 1st task is completed enter 2nd task
	{
		l4task2:
		currenttaskno=2;
		int number;
		stddisplay;
		cout<<endl<<"A troll stops you on your way. Afraid of his huge body and his dangerous-looking club, you decide to stop and listen to what he has to say.\n";
		cout<<" 'My mistress the daughter of Zeus parked her chariot in this parking lot,' he grunts and indicates a stone parking lot behind him.";
		cout<<" 'The parking spaces have numbers, but I have forgotten what space she parked it on, and the valet refuses to give me the keys to the chariot unless I can tell him the number.'\n ";
		cout<<"You walk over to the parking lot and see the grand silver-black chariot parked on a spot, hiding its number. To the left are 4 empty spaces, reading 16, 06,68 and 88.";
		cout<<"To the right is just one empty space, reading 98. You walk over to the troll. 'O great troll,' you say so as not to offend him.";
		cout<<" 'You're so strong and big. Why don't you lift up the chariot and find out the parking space's number?' The troll grins evilly.";
		cout<<" 'I haven't eaten for a while now, so I am not as strong. But I could eat you and lift up the chariot,' he says. \n";
		cout<<"Oops. Looks like you either have to guess the number or be eaten up by the troll. You look to Syvian for help. 'I told you, pal,' he says apologetically.";
		cout<<" 'Maths is not my forte. But then,' he says suddenly. 'Maybe you don't need Maths at all. Maybe-' 'Oi, you!' the troll interrupts. 'I asked the human, not you, elf!";
		cout<<"Do you want to be dessert?'\n Terrified, Syvian falls silent. Looks like you're on your own. What's the chariot's parking spot's number? \n";
		wannaexit();
		cin>>number;
		if(number==87)
		{
			flag=4;
			levelupsound();
			cout<<"That's correct! Syvian was right- you didn't need any Maths at all; just a change of perspective. The troll gets the chariot keys and grudgingly allows his dinner to go away to the next level.";
			wannaexit();
		}
		else
		{
			flag=3;
			wrongsound();
			cout<<"Don't bother your pretty head too much. All you need to do is, look at the numbers upside down: \n";
			cout<<"\n |86|	|88|89|90| \n";
			cout<<"And the answer is simple- 87. The troll has the pleasure of feasting on you";
			wannaexit();
		}
	}
	/*else if 1st task fails
	goes back to calling statement in main and restarts level 4*/
}

struct cpr
{
	char Handposition[7];
	int otherhand,compression_number,compression_rate;
	float pressure;
	int head,chin,mouth,nose; //tilt head, lift chin, open mouth,pinch nose
	int nextstep;
};

void level5(int taskno)
{
	currentlevelno=5;
	if(taskno==1)
		goto l5task1;
	else if(taskno==2)
		goto l5task2;
	else if(taskno==3)
		goto l5task3;
	l5task1:
	currenttaskno=1;
	stddisplay;
	int num;     //task 1
	cout<<endl<<"Now that you've advanced to level 5, you need to worm your way past the assassins' base.\n";
	cout<<"Although you have Excalibur, you're not trained enough to use it, and the assassins are very dangerous- they can kill in the blink of an eye.";
	cout<<"But don't be disheartened- there's still one way to get past them. In order to get in, you have to give the correct countersign to the guard at the gate after he gives you the sign.";
	cout<<"You and Syvian hide behind a bush to catch the countersign. One assassin comes and the guard says '6'. The assassin says '3' and gets in. \n";
	cout<<"Another assassin comes and the guard says '12'. The assassin says '6' and gets in.\n";
	cout<<" 'I'm not good at Maths, but even I know the rule now,' Syvian whispers excitedly and before you can say anything, runs off to the entrance.\n";
	cout<<"The guard says '10'. Syvian confidently answers with a '5', but what is this? The guard shoots him down. You're horrified.";
	cout<<"Elves are stronger than humans in life-and-death situations, but if you don't do something soon, Syvian will definitely die. For that, you first have to get past the assassins.";
	cout<<"\n Seeing no other choice, you stroll up to the guard. He says '8'. What should you answer to get past him? ";
	cout<<"Type a number: ";
	wannaexit();
	cin>>num;
	if(num==5)
	{
		flag=1;
		rightsound();
		cout<<"The guard, although suspicious, lets you pass. You figured the rule out correctly- it's the number of letters in the name of the number the guard says.";
		wannaexit();
	}
	else
	{
		flag=3;
		wrongsound();
		cout<<"That's the wrong answer! The guard shoots you down too. The rule for the countersign is-the number of letters in the name of the number the guard says.";
		defeat;
	}

	if(flag==1) //if 1st task is completed
	{
		l5task2:
		currenttaskno=2;
		stddisplay;
		cpr syvian;
		int revive=0;
		char handposition1[7]="centre",handposition2[7]="center";
		cout<<endl<<"Now your first priority is to revive Syvian. You run to him and almost faint- he isn't breathing. \n";
		cout<<"Getting help would take too long, so your only choice is to give him CPR(Cardio-Pulmonary Resuscitation)";
		cout<<"\n To give him CPR, where on the chest should you place your hand? (Type one word): ";
		wannaexit();
		cin>>syvian.Handposition;
		if(strcmpi(syvian.Handposition,handposition1)==0||strcmpi(syvian.Handposition,handposition2)==0)
			revive++;
		cout<<"2nd step: What should you do with your other hand?(Press a number) \n";
		cout<<"1. Place it on the left side of his chest \n";
		cout<<"2. Place it on the right side of his chest \n";
		cout<<"3. Pinch his nose with it \n";
		cout<<"4. Interlock it with your first hand \n";
		wannaexit();
		cin>>syvian.otherhand;
		if(syvian.otherhand==4)
			revive++;
		cout<<"How far down should you push his chest? Type your answer in inches: ";
		wannaexit();
		cin>>syvian.pressure;
		if(syvian.pressure>=1.5&&syvian.pressure<=2)
			revive++;
		cout<<"How many compressions should you give him? Type a number: ";
		wannaexit();
		cin>>syvian.compression_number;
		if(syvian.compression_number==30)
			revive++;
		cout<<"What's the rate of the compressions (in compressions per minute) you should give him? Type a number: ";
		cin>>syvian.compression_rate;
		if(syvian.compression_rate>=100&&syvian.compression_rate<=120)
			revive++;
		cout<<"The elf doesn't open his eyes yet. You'll have to proceed to the next step of cpr- mouth-to-mouth resuscitation. \n";
		cout<<"To do it right, what should you do with his head? (Type a number): \n";
		cout<<"1. Tilt it backwards \n 2.Tilt it forwards \n 3.Lift it up \n 4.Cover it \n";
		wannaexit();
		cin>>syvian.head;
		if(syvian.head==1)
			revive++;
		cout<<"Now what should you do with the chin? \n";
		cout<<"1.Lift it and support it with one hand \n";
		cout<<"2. Let it be \n 3.Press it down \n";
		wannaexit();
		cin>>syvian.chin;
		if(syvian.chin==1)
			revive++;
		cout<<"What should you do with the mouth? \n";
		cout<<"1. Open it wide \n";
		cout<<"2. Let it fall open slightly \n";
		wannaexit();
		cin>>syvian.mouth;
		if(syvian.mouth==2)
			revive++;
		cout<<"What should you do with the nose? \n";
		cout<<"1. Leave it as it is \n 2.Pinch it \n";
		cout<<"3.Lift it slightly and support it \n";
		wannaexit();
		cin>>syvian.nose;
		if(syvian.nose==2)
			revive++;
		cout<<"Now for the last step. What should you do next? \n";
		cout<<"1.Take a huge breath, put your mouth over Syvian's, and blow until you can see his chest rise. Remove your mouth from his and look along the chest, watching the chest fall. \n";
		cout<<"2.Take a small breath, put your mouth over Syvian's, and blow until you can see his chest fall. Remove your mouth from Syvian's and look along the chest, watching the chest rise. \n";
		cout<<"3.Take a huge breath, put your mouth over Syvian's, and blow until you can see his chest fall. Remove your mouth from the Syvian's and look along the chest, watching the chest rise. \n";
		cout<<"4.Take a normal breath, put your mouth over Syvian's, and blow until you can see his chest rise. Remove your mouth from Syvian's and look along the chest, watching the chest fall. \n";
		wannaexit();
		cin>>syvian.nextstep;
		if(syvian.nextstep==4)
			revive++;
		if(revive>6)
		{
			flag=1;
			rightsound();
			clrscr();
			stddisplay;
			cout<<"\nSyvian gasps and opens his eyes. Your happiness knows no bounds. \n";
			cout<<" '"<<currentplayer.name<<", you're awesome.'";
			cout<<"\n \n Would you like to see the steps of cpr summarised? Press 1 for yes and any other number for no \n";
			int summary;
			cin>>summary;
			if(summary==1)
			{
				cout<<"1.Make sure the patient is lying on his back on a firm surface. Kneel beside him and place the heel of your hand on the center of the chest. \n";
				cout<<"2.Keeping your arms straight, cover the first hand with the heel of your other hand and interlock the fingers of both hands together. Keep your fingers raised so they do not touch the patient’s chest or rib cage. \n";
				cout<<"3.Lean forward so that your shoulders are directly over the patient’s chest and press down on the chest about two inches. Release the pressure, but not your hands, and let the chest come back up. \n";
				cout<<"4.Repeat to give 30 compressions at a rate of 100 compressions per minute. Not sure what that really means? Push to beat of the Bee Gees song 'Stayin’ Alive.' \n";
				cout<<"5.Move to the patient’s head. Tilt his head and lift his chin to open the airway again. Let his mouth fall open slightly. \n";
				cout<<"6.Pinch the nostrils closed with the hand that was on the forehead and support the patient’s chin with your other hand. Take a normal breath, put your mouth over the patient’s, and blow until you can see his chest rise. \n";
				cout<<"7.Remove your mouth from the patient’s and look along the chest, watching the chest fall. Repeat steps six and seven once. \n";
				cout<<"8.Place your hands on the chest again and repeat the cycle of 30 chest compressions, followed by two rescue breaths. Continue the cycle. \n";
				wannaexit();
			}
		}
		else
		{
			flag=3;
			wrongsound();
			clrscr();
			cout<<"You look on in dismay as Syvian lies limp and unmoving because of your failed efforts.";
			defeat;
		}
	}
	else      //if 1st task fails
		return;  //to calling statement in main and restart level 4

	if(flag==1) //if 2nd task is accomplished, enter 3rd
	{
		l5task3:
		currenttaskno=3;
		stddisplay;
		int points=0;
		char identityblue[7],identityred[7],identitygreen[7];
		char blueidentity[7]="knight",redidentity[7]="spy",greenidentity[7]="knave";
		cout<<endl<<"On the island of knights and knaves and spies, where Syvian's powers can't work, you are approached by three people wearing different colored clothes. You know that one is a knight, one is a knave, and one is a spy. They speak in the following order: \n";
		cout<<"The man wearing blue says, 'I am a knight.' \n";
		cout<<"The man wearing red says, 'He speaks the truth.' \n";
		cout<<"The man wearing green says, 'I am a spy.' \n";
		cout<<"Who is the knight, who is the knave, and who is the spy? The only thing Syvian is able to tell you is this- knights always tell the truth, knaves always lie, and spies can lie or tell the truth at will. \n";
		cout<<"Enter the identity of the man in blue(knight,knave or spy): ";
		wannaexit();
		gets(identityblue);
		cout<<"Enter the identity of the man in red(knight,knave or spy): ";
		wannaexit;
		gets(identityred);
		cout<<"Enter the identity of the man in green(knight,knave or spy): ";
		wannaexit;
		gets(identitygreen);
		if(strcmpi(identityblue,blueidentity)==0)
			points++;
		if(strcmpi(identityred,redidentity)==0)
			points++;
		if(strcmpi(identitygreen,greenidentity)==0)
			points++;
		if(points==3)
		{
			flag=5;
			levelupsound();
			cout<<"Your deduction's on point! Congratulations on levelling up!";
			wannaexit();
		}
		else
		{
			flag=3;
			currentplayer.lives--;
			wrongsound();
			cout<<"So close! Looks like your reasoning failed this time. Would you like to view the solution? Press 1 for yes and any other number for no ";
			int sol;
			wannaexit();
			cin>>sol;
			if(sol==1)
			{
				cout<<"Let's begin by taking the first thing that was said at face value. The man wearing blue said, 'I am a knight.' If it is true, and he is a knight, then he would tell you so, so that checks out. \n\n";
				cout<<"The man wearing red then says, 'He speaks the truth.' Since we already assume he is telling the truth, that he is a knight and says so, then this statement would also be true. But since there is only one knight, and we assume it to be the man in blue, the man in red must be the spy, who happens to be telling the truth this time. \n\n";
				cout<<"This leaves the man wearing green, who says, 'I am a spy.' If we assume the man in blue is the knight and the man in red is the spy, then the man in green must be the knave, and as the knave, claiming that he is a spy would be a lie, which checks out. \n\n";
				cout<<"And that is our solution: the man in blue is the knight, the man in red is the spy, and the man in green is the knave. \n\n";
				cout<<"Let's double check the solution by assuming the first statement is a lie. The man in blue says, 'I am the knight,' and if he were lying, he could be either the spy or the knave claiming to be a knight.";
				cout<<"The man in red then says, 'He speaks the truth,' but we are assuming he lied, so the man in red must also be lying. At this point, we think the man in blue and the man in red could both be either knaves or spies, both lying. \n\n";
				cout<<"But when we get to the man in green, who says, 'I am a spy,'we realize that this scenario cannot be possible.";
				cout<<"If the man in blue is lying, then the man in red must also be lying, and therefore neither are knights, and we know there is at least one knight, so it must be the man in green.";
				cout<<"But the man in green claims to be a spy, which an honest knight would never do. So it is not possible for the man in blue to be lying, knowing that there is one knight, one knave, and one spy among the group.";
				wannaexit();
			}

		}
	}
	/*else if 2nd task fails
	return to calling statement in main and restart level 4 */
}

void level6(int taskno)
{
	currentlevelno=6;
	char rightans1[12]="vegetables",rightans2[12]="vegetable";
	if(taskno==1)
		goto l6task1;
	else if(taskno==2)
		goto l6task2;
	l6task1:
	currenttaskno=1;
	stddisplay;
	char answer[12];
	cout<<endl<<"As soon as you enter level 6, you find the Jester waiting for you. \n";
	cout<<" 'Me been waiting for you, masters! But me's gon let you go on'y if you answer me's question!' \n";
	cout<<" 'Simple 'un, really. Me 'unce knew a clerk in the vegetable shop wh'was 5'10'' tall. Tell I, what did he weigh?\n";
	wannaexit();
	gets(answer);
	if(strcmpi(answer,rightans1)==0||strcmpi(answer,rightans2)==0)
	{
		flag=1;
		rightsound();
		cout<<"Amazing! You smoothly dodged the Jester's trick question. Move ahead!";
		wannaexit();
	}
	else
	{
		flag=3;
		wrongsound();
		cout<<"It was a trick question! The right answer is vegetables, because the clerk in the vegetable shop can weigh nothing but vegetables!";
		defeat;
	}

	if(flag==1) //2nd task
	{
		l6task2:
		currenttaskno=2;
		stddisplay;
		char rightans[10]={"lightning"},ans[10];
		cout<<endl<<"Next, both of you stumble upon the Jester's little sister. \n";
		cout<<" 'Oh no,' Syvian facepalms. 'What?' you ask him. 'This is Thexina, who's a complete literature geek.";
		cout<<"She's gonna ask you a riddle which has been written by some poet or writer, and believe me, they are HARD.' \n";
		cout<<"Not encouraged, you nevertheless have to approach Thexina. 'Welcome, wanderers, and indulge yourself in Emily Dickinson's poetry \n'";
		cout<<" 'I am, in truth, a yellow fork \n From Tables in the sky \n";
		cout<<"By inadvertent fingers dropt \n The awful Cutlery \n\n";
		cout<<"Of mansions never quite disclosed \n And never quite concealed \n";
		cout<<"The Apparatus of the Dark \n To ignorance revealed.' \n";
		cout<<"What's this thing Thexina is talking about?(type one word) \n";
		wannaexit();
		gets(ans);
		if(strcmpi(ans,rightans)==0)
		{
			flag=6;
			levelupsound();
			cout<<"Exactly! The title of this Emily Dickinson poem is, in fact, 'The Lightning is a yellow fork'. \n";
			cout<<"Thexina doesn't seem too pleased about letting you level up, though.\n";
			cout<<"Also, congratulations! You've just passed a checkpoint, which means the next time you lose a life, you'll start from level 7, not level 1.";
			wannaexit();
		}
		else
		{
			flag=3;
			wrongsound();
			cout<<ans<<" is incorrect. The right answer is lightning.The title of this Emily Dickinson poem is, in fact, 'The Lightning is a yellow fork'. \n";
			defeat;
		}
	}
	/*else if 2nd task fails
	return to calling statement in main and restart level 4 */
}

void level7()
{
	currentlevelno=7;
	stddisplay;
	int choice[5],score=0,rightchoice[5];
	char useroption[5][12];
	rightchoice[0]=1;
	rightchoice[1]=4;
	rightchoice[2]=4;
	rightchoice[3]=4;
	rightchoice[4]=2;
	cout<<endl<<"Homophones -one of two or more words pronounced alike but different in meaning or derivation or spelling.They're also tricky little buggers, and they're here to bug you.";
	cout<<"A landmine of homophones- that's your next obstacle. Get 3 or less right, and they'll go off, deafening you with a cacophony of similar-sounding words. Get 4 or more right, and you'll pass with minor injuries. The rules are simple- a sentence, a blank or two and three or four options.";
	cout<<" To answer any question, choose an option by typing a number. Whenever you're ready, press any key.";
	wannaexit();
	clrscr();
	char rightword[5][20]={{"indite"},{"moat"},{"phiz"},{"rite,wright"},{"counsel"}};
	char questions[5][150]={
	{"It was a tempestuous night when I sat down at the desk to ______ a letter to my children."},
	{"I'm sorry to tell you that all of your presents fell out the window and into the ______."},
	{"None of Jake's friends recognized him since he'd had the surgeon do the work on his ______."},
	{"They hired the eulogist for the woodworker's funeral because they thought he could write the right ______ for the recently deceased ______."},
	{"If I were to ______ you, I would say to not take the job."}
	};
	cout<<questions[0]<<endl;
	char options1[3][8]={{"indite"},{"indict"},{"indight"}};
	cout<<"1.indite \n 2.indict \n 3.indight \n";
	wannaexit();
	cin>>choice[0];
	strcpy(useroption[0],options1[choice[0]-1]);
	if(choice[0]==1)
		score++;
	clrscr();
	cout<<questions[1]<<endl;
	char options2[4][5]={{"mote"},{"moet"},{"mott"},{"moat"}};
	cout<<"1.mote \n 2.moet \n 3.mott \n 4.moat \n";
	wannaexit();
	cin>>choice[1];
	strcpy(useroption[1],options2[choice[1]-1]);
	if(choice[1]==4)
		score++;
	clrscr();
	cout<<questions[2]<<endl;
	char options3[4][6]={{"fizz"},{"phizz"},{"fiz"},{"phiz"}};
	cout<<"1.fizz \n 2.phizz \n 3.fiz \n 4.phiz \n";
	wannaexit();
	cin>>choice[2];
	strcpy(useroption[2],options3[choice[2]-1]);
	if(choice[2]==4)
		score++;
	clrscr();
	cout<<questions[3]<<endl;
	char options4[4][12]={{"right,write"},{"write,right"},{"wright,rite"},{"rite,wright"}};
	cout<<"1.right,write \n 2.write,right \n 3.wright,rite \n 4.rite,wright \n";
	wannaexit();
	cin>>choice[3];
	strcpy(useroption[3],options4[choice[3]-1]);
	if(choice[3]==4)
		score++;
	clrscr();
	cout<<questions[4]<<endl;
	char options5[3][8]={{"council"},{"counsel"},{"cancel"}};
	cout<<"1.council \n 2.counsel \n 3.cancel \n";
	wannaexit();
	cin>>choice[4];
	strcpy(useroption[4],options5[choice[4]-1]);
	if(choice[4]==2)
		score++;

	if(score>3)
	{
		flag=7;
		levelupsound();
		cout<<"Great/grate! You've overstepped the minefield of homophones!";
		cout<<"Your score is "<<score<<".";
		if(score!=5)
		{
			cout<<"This is where you went wrong: \n";
			for(int i=0;i<5;i++)
			{
				if(choice[i]!=rightchoice[i])
				{
					cout<<"Question no."<<i+1<<") "<<questions[i];
					cout<<" \n Your answer: "<<choice[i]<<") "<<useroption[i];
					cout<<"\n Right answer: "<<rightchoice[i]<<") "<<rightword[i];
					cout<<endl;
				}
			}
		}
		wannaexit();
	}
	else
	{
		flag=6;
		wrongsound();
		cout<<"Your score is "<<score<<". A pity- you fell short by just "<<4-score<<" points. Better luck next time.";
		cout<<"This is where you went wrong: \n";
		for(int i=0;i<5;i++)
		{
			if(choice[i]!=rightchoice[i])
			{
				cout<<"Question no."<<i+1<<") "<<questions[i];
				cout<<"\n Your answer: "<<choice[i]<<") "<<useroption[i];
				cout<<"\n Right answer: "<<rightchoice[i]<<") "<<rightword[i];
				cout<<endl;
			}
		}
		defeat;
	}
}

void level8(int taskno)
{
	currentlevelno=8;
	char rightcolour[6]="black",colour[6];
	if(taskno==1)
		goto l8task1;
	else if(taskno==2)
		goto l8task2;
	l8task1:
	currenttaskno=1;
	stddisplay;
	//1st task
	cout<<endl<<"The Grandmaster stops both of you for a logic game with his apprentice. 'Quite a sensitive man, he is,' Syvian tells you. 'So it's best to respect his wishes.' \n";
	cout<<"The Grandmaster takes the three of you inside a room and shows all of you 5 hats - two white and three black.\n";
	cout<<"Then he turns off the lights and puts a hat on each player's head. After that he hides the remaining two hats, but before he can turn the lights on, you announce the color of your hat, and you're right.\n";
	cout<<"What color is your hat? \n";
	cout<<"Hint: The Grandmaster is a just man who'll give each of you a fair chance of winning.";
	wannaexit();
	gets(colour);
	if(strcmpi(colour,rightcolour)==0)
	{
		flag=1;
		rightsound();
		cout<<"Good work! The Grandmaster is impressed with your logical ability and allows you to pass.";
		wannaexit();
	}
	else
	{
		flag=6;
		wrongsound();
		cout<<"That's the wrong answer! Press 1 to view the solution, and any other number to continue without viewing the solution ";
		int a;
		currentplayer.lives--;	//defeat
		wannaexit();
		cin>>a;
		if(a==1)
		{
			cout<<"The important thing here is that all of you have equal chances to win.";
			cout<<"If one of you had been given a black hat and the others white hats, the one with black hat would immediately have known his color (unlike the others).";
			cout<<"So 1 black and 2 white hats is not a fair distribution.\n";
			cout<<"If there had been one white and two black hats distributed, then the two with black hats would have had advantage.";
			cout<<"They would have been able to see one black and one white hat and supposing they had been given white hat, then the one with black hat must at once tell his answer. \n";
			cout<<"However, if he had remained silent, then the players with black hats would have known that they wear black hats, whereas the one with white hat would have been forced to eternal thinking with no clear answer.";
			cout<<"So neither is a fair situation.\n";
			cout<<"That's why the only way of giving each player an equal chance is to distribute hats of one color - so 3 black hats.";
		}
		wannaexit();
	}

	if(flag==1) 	//enter 2nd task if 1st task suceeds
	{
		l8task2:
		currenttaskno=2;
		stddisplay;
		cout<<endl<<"As you move forward, Syvian suddenly spots another elf strolling near a church and almost faints, then recomposes himself. \n";
		cout<<"You steady him and ask him what the matter is. He grits his teeth and replies- 'I am so gonna kill Lazarus, that son of a gun.";
		cout<<"He killed my sister and now he places a shapeshifter in her shape as an obstacle? That-' Syvian swears. You calm him down and ask him to tell you more about shapeshifters. \n";
		cout<<"'I don't know much about them, really. Never encountered one before. All I know is that they can take the shape of any living creature, and there's only one way to kill them, but I don't know how.' \n";
		cout<<"You look at the shapeshifter/Syvian's sister, sitting on the stump of an oak tree and playing with matches. You don't know anything about shapeshifters either, but you've got to kill the one in front of you somehow, to save your elven friend from serious emotional trauma.";
		wannaexit();
		clrscr();
		stddisplay;
		int weapon;
		cout<<"\nYou don't know how to kill it either, but if you've been paying attention to the scene before you, you do. What's the weapon you must use to kill the shapeshifter? \n";
		cout<<"1.Douse it with holy water from inside the church \n";
		cout<<"2.Stab it with your silver-bladed Excalibur \n";
		cout<<"3.Fashion a stake from oak wood and thrust it through the shapeshifter \n";
		cout<<"4.Set it on fire \n";
		wannaexit();
		cin>>weapon;
		if(weapon==2)
		{
			flag=8;
			levelupsound();
			cout<<"That's right!And that's the sound of you levelling up. Silver is the only thing that can kill a shapeshifter. Excalibur came in handy, after all.";
			wannaexit();
		}
		else
		{
			flag=6;
			wrongsound();
			cout<<"Wrong! As you saw, the shapeshifter was strolling near a church, which it wouldn't do if any kind of holy thing would harm it. \n";
			cout<<"So holy water's out. It was sitting on an oak stump, so oak stakes won't kill it as well. Neither will fire, since it was playing with matches. ";
			cout<<"So, the only option left is to use your silver blade, and indeed, silver is the only thing fatal to shapeshifters.";
			defeat;
		}
	}
	/*else if 2nd task fails
	return to calling statement in main and restart level 7 */


}

void level9(int taskno)
{
	currentlevelno=9;
	if(taskno==1)
		goto l9task1;
	else if(taskno==2)
		goto l9task2;
	l9task1:
	currenttaskno=1;
	stddisplay;
	double ans;          //1st task
	cout<<endl<<"You've met the chemist and the biologist. Lazarus himself is the physicist. So, you next meet- that's right, the mathematician. \n";
	cout<<"He asks you to solve this puzzle by recognising the pattern: \n";
	cout<<"1,11,21,1211,111221,?";
	cout<<"There's more to it than meets the eye, clearly. \n";
	cout<<"What will come in place of the question mark? \n";
	wannaexit();
	cin>>ans;
	if(ans==312211)
	{
		flag=1;
		rightsound();
		cout<<"Well done! 312211 is correct.If you worked it out, brilliant!";
		cout<<"But if you guessed the answer and just got lucky, press 1 to view the explanation, and any other number to simply move on.";
		int a;
		cin>>a;
		if(a==1)
		{
			cout<<endl<<"Let's look at the 1st number- 1. It is one 1, so the next number is 11.\n ";
			cout<<"Now 11 is two 1s, so the next number is 21. 21 is one 2 and one 1, so the next number is 1211. \n";
			cout<<"In this way, each number is the count of each digit in the number before it. Thus, you get 312211 as the answer.";
			wannaexit();
		}
		wannaexit();
	}
	else
	{
		flag=6;
		wrongsound();
		cout<<ans<<" is wrong. The correct answer is 312211. Press any key to learn why.";
		getch();
		cout<<endl<<"Let's look at the 1st number- 1. It is one 1, so the next number is 11.\n ";
		cout<<"Now 11 is two 1s, so the next number is 21. 21 is one 2 and one 1, so the next number is 1211. \n";
		cout<<"In this way, each number is the count of each digit in the number before it. Thus, you get 312211 as the answer.";
		defeat;
	}
	if(flag==1) 	       //2nd task
	{
		l9task2:
		currenttaskno=2;
		stddisplay;
		char rightstring[6]="BRASS",string[6];
		cout<<endl<<"You've finally arrived at Lazarus's fortress! But getting inside isn't easy- you'll have to figure out the password to get inside.";
		cout<<"\n There could be a million possible permutations, but Syvian narrows it down for you.";
		cout<<"His sister used to work in the fortress before she was killed, and she had striken up quite a friendship with Mevoina, a guard at the entrance.";
		cout<<"After making sure that you're out of Mevoina's sight, he persuades her to give a hint for the password, and this is what she tells him: \n";
		cout<<"49+7=RUN \n 6+85=CAT \n 5+76+16=BOSS \n The password is 35+33+16 \n";
		cout<<"What's the password to the fortress's gate? ";
		wannaexit();
		gets(string);
		if(strcmpi(string,rightstring)==0)
		{
			flag=9;
			levelupsound();
			cout<<"That's right! According to the periodic table, 35=Bromine (Br) \n";
			cout<<"33=Arsenic(As) \n 16=Sulphur(S) \n So, 35+33+16= BRASS";
			cout<<"\n\n Also, congratulations! You've just passed a checkpoint, which means the next time you lose a life, you'll start from level 10, not level 1.";
			wannaexit();
		}
		else
		{
			flag=6;
			wrongsound();
			cout<<"So close! You were about to get in, but the password is wrong. The alarm activates and the guards throw you down the hill.";
			defeat;
		}
	}
	/*else if 2nd task fails
	return to calling statement in main and restart level 7 */
}

void level10(int taskno)
{
	currentlevelno=10;
	char ridans[6]="XVIII",ans[6];	//for task 1
	if(taskno==1)
		goto l10task1;
	else if(taskno==2)
		goto l10task2;
	l10task1:
	currenttaskno=1;
	stddisplay;
	cout<<endl<<"The two headed snake who met you at the base of the mountain returns with a riddle:\n";
	cout<<"The key to this riddle is only for you \n";
	cout<<"Below are instructions, above this the clue \n";
	cout<<"First strike the one near the head of a year \n";
	cout<<"Then remove he who begins a cheer \n";
	cout<<"Next take away the end of a tunnel \n";
	cout<<"Then let us go to solve this puzzle \n";
	cout<<"What you first took you must now take again \n";
	cout<<"With three you are left, but fret not dear friend \n";
	cout<<"Fattest to front and thinnest to rear \n";
	cout<<"Add in two 'eyes' and all becomes clear \n";
	cout<<"'I have a feeling the clues are quite literal',Syvian manages to whisper before the snakes silence him with a hiss. \n";
	cout<<"Type in the answer: ";
	wannaexit();
	gets(ans);
	if(strcmpi(ans,ridans)==0)
	{
		flag=1;
		rightsound();
		cout<<"That's right! The answer is XVIII, or 18 in Roman numerals. \n";
		cout<<"The key is only for you- EXCLUSIVE. Remove the one near the head of a year- E. Remove he who begins a cheer- C. Remove the end of the tunnel- L. Remove us- U and S. Remove again E. Now you are left with X, I, V. Arrange them fattest to front and thinnest to rear- X > V > I. Add two 'eyes'-I and I, so you get XVIII=18.";
		wannaexit();
	}
	else
	{
		flag=9;
		wrongsound();
		cout<<"Wrong! The answer is XVIII, or 18 in Roman numerals. \n";
		cout<<"The key is only for you- EXCLUSIVE. Remove the one near the head of a year- E. Remove he who begins a cheer- C. Remove the end of the tunnel- L. Remove us- U and S. Remove again E. Now you are left with X, I, V. Arrange them fattest to front and thinnest to rear- X > V > I. Add two 'eyes'-I and I, so you get XVIII=18.";
		defeat;
	}

	if(flag==1) 	//final task
	{
		l10task2: ;
		currenttaskno=2;
		stddisplay;
		char rightmessage[47]="I am not a mad scientist just a brilliant one",message[47];
		cout<<endl<<"At long last, you see the Dehumaniser in front of you- a huge metal contraption with a long glass tube in the centre, and lots of buttons and levers.\n";
		cout<<"It looks complex, but deactivating it is a simple task- all you have to do is decrypt the message displayed on the narrow glass screen in the front: \n";
		cout<<"IAITBAAMEJRNMANUITNDTSLOOSITLNTCSAIE \n";
		cout<<"Quick now, before Lazarus returns with the Technetium Kryptonite. Type in the decrypted message, with spaces but without punctuation marks: ";
		wannaexit();
		gets(message);
		if(strcmpi(message,rightmessage)==0)
		{
			flag=10;
			currentlevelno=11;
			celebrationsound();
			cout<<"Finally! You've deactivated the Dehumaniser, and humanity is saved, all thanks to you,"<<currentplayer.name<<"!";
			cout<<"Your hard work bore fruit! Congratulations!";
			wannaexit();
		}
		else
		{
			flag=9;
			wrongsound();
			cout<<"My god, you almost saved all of humanity. ALMOST. Press any key to have another shot at it";
			defeat;
		}
	}
		/*else if 2nd task fails
	return to calling statement in main and restart level 10 */
}
void main(char input)
{
	if(input=='s')
		goto story;
	else if(input=='o')
		goto l1;
	clrscr();
	int choice;
	do
	{
		clrscr();
		cout<<"\n\n\n\t\t Welcome to Lazarus Rising. Please choose an option.";
		cout<<"\n \t\t 1.Start new game(sign up) \n \t\t 2.Continue an old game(sign in)";
		cout<<"\n \t\t 3.Change your password \n \t\t 4.Delete your profile";
		cout<<"\n \t\t 5.Open developer menu \n \t\t";
		cout<<" 6.Exit \n \t\t";
		gotoxy(35,23);
		cout<<"Game Developer: Anisha Jain";
		gotoxy(35,24);
		cout<<"Class: XII-A";
		gotoxy(18,11);
		cin>>choice;
		if(choice==1)
			createprofile();
		else if(choice==2)
			openprofile();
		else if(choice==3)
			changepassword();
		else if(choice==4)
			deleteprofile();
		else if(choice==5)
		{
			char securitykey[20];
			int attempts=0;
	entersk:	cout<<"Enter the security key: ";
			strcpy(securitykey,enterpassword());
			if(strcmp(securitykey,"Ford Prefect_42")==0)
				developermenu();
			else if(attempts<=3)
			{
				attempts++;
				cout<<"\n Wrong. Try again. \n";
				goto entersk;
			}
			else
			{
				cout<<"Too many failed attempts. Exiting...";
				getch();
				exit(1);
			}
		}
		else if(choice==6)
			exit(1);
		else
		{
			cout<<"There is no option "<<choice<<" ,overly-wise one. Choose again.";
			getch();
		}
	}while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6);
	clrscr();
	if(choice==2)
		goto levelsequence;
	story:
	cout<<currentplayer.name<<", there's something you need to know before you begin in your mission.";
	cout<<endl<<"Lazarus wasn't always a mad scientist.";
	cout<<"In fact, he was a brilliant child who could've been a godsend to this world had he not witnessed his father die.";
	cout<<endl<<"His father was an army officer who died from a gunshot to the head when the terrorists invading the city took advantage of his momentary trauma on watching his wife being knifed by another terrorist.";
	cout<<"That day, little Robert Lazarus became convinced that emotions were humankind's biggest weakness and made it his life mission to erase them from every human being.";
	cout<<endl<<"And for that, he put his scientific mind to the task and set about creating a contraption to delete what makes human beings human.";
	cout<<"And he did succeed. Today is the fateful day when he will insert his final element, the rare Technetium Kryptonite into his devious Dehumaniser.";
	cout<<endl<<"But there's a catch- Lazarus couldn't build his machine unless it had an Achilles' heel, a fatal weakness.";
	cout<<"And that Achilles' heel is you.";
	cout<<endl<<"The young scientists and historians at The Humanity Society have determined it.";
	cout<<"They don't exactly know why, but you're the only one who can stop Lazarus. ";
	cout<<"And today you have a chance. Today, Lazarus has gone out from his fortress atop Mount Colnis to bring the Technetium Kryptonite.";
	cout<<endl<<"But he is a clever man- he has secured the path to his fortress with all kinds of traps.";
	cout<<"You'll have to be very careful, because you only get three chances if you fail at any point. Are you ready, brave one?";
	cout<<endl<<"Press any key to continue.";
	getch();
	clrscr();
	cout<<"A few simple rules before you start: \n";
	cout<<"1.You get a checkpoint after levels 3,6 and 9. However, if at any point during the game, you lose ALL of your lives, the game restarts.\n";
	cout<<"2.If you want to exit the game at any time, just press '!' from your keyboard. Your progress will automatically be saved. \n";
	cout<<"3.Before entering any answer to any question, press any key(except !) once.\n";
	cout<<"4.After you've completed a particular task, to move on to the next task, press any key once.";
	cout<<endl<<"Press any key to continue.";
	wannaexit();
l1:	level1();
	levelsequence:
	if(flag==1)    //if level 1 is passed
		level2();
	else if(flag==0)      //if level 1 is failed
		goto l1;
	if(flag==2)	//if level 2 is passed
		level3();
	else if(flag==0)
		goto l1;
l3:	if(flag==3) //if level 3 is passed
		level4();
	else if(flag==0)
		goto l1;
	if(flag==4) //if level 4 is passed
		level5();
	else if(flag==3)
		goto l3;
	if(flag==5) //if level 5 is passed
		level6();
	else if(flag==3)
		goto l3;
l6:	if(flag==6) //if level 6 is passed
		level7();
	else if(flag==3)
		goto l3;
	if(flag==7) //if level 7 is passed
		level8();
	else if(flag==6)
		goto l6;
	if(flag==8) //if level 8 is passed
		level9();
	else if(flag==6)
		goto l6;
l9:	if(flag==9) //if level 9 is passed
		level10();
	else if(flag==6)
		goto l6;
	if(flag==10) //if level 10 is passed
		main();
	else if(flag==9)
		goto l9;
	getch();
}
