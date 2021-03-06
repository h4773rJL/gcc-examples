/*
 * calculadora.c
 * Tuxes Team
 * 
 * Copyright 2015 intel trainnig <intel@Intel-BUAP>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <libintl.h>
#include <locale.h> 
#include <math.h>

#define _(cadena) gettext(cadena)

int print_menu()
{
	// vars for the screen size and position, i to rows
	
    int row, col, rrow = 0, acol=0, bcol=0, i=2, value=0;
    getmaxyx(stdscr,row,col);    
    acol=2; bcol=(col/2)+2;
    char *tit=_("Cientific Calculator");
	clear();
    mvprintw (rrow, (col-strlen(tit))/2,"%s",tit);    
    mvprintw (rrow+i,acol,_("1.  add"));
    mvprintw (rrow+i,bcol,_("2.  Subtract"));
    i++; //3
    mvprintw (rrow+i,acol,_("3.  multiply") );
    mvprintw (rrow+i,bcol,_("4.  Divide"));
    i++; //4
    mvprintw (rrow+i,acol,_("5.  sine"));
    mvprintw (rrow+i,bcol,_("6.  cosine"));
    i++; //5
    mvprintw (rrow+i,acol,_("7.  tangent") );
    mvprintw (rrow+i,bcol,_("8.  atan"));
    i++; //6
    mvprintw (rrow+i,acol,_("9.  atan2"));
    mvprintw (rrow+i,bcol,_("10. acos"));
    i++; //7
    mvprintw (rrow+i,acol,_("11. asin"));
    mvprintw (rrow+i,bcol,_("12. square"));
    i++; //8
    mvprintw (rrow+i,acol,_("13. pow"));
    mvprintw (rrow+i,bcol,_("14. log"));
    i++; //9
    mvprintw (rrow+i,acol,_("15. log10"));
    mvprintw (rrow+i,bcol,_("16. ldexp"));
    i++; //10
    mvprintw (rrow+i,acol,_("17. exp"));
    mvprintw (rrow+i,bcol,_("18. cosh"));
    i++; //11
    mvprintw (rrow+i,acol,_("19. sinh"));
    mvprintw (rrow+i,bcol,_("20. tanh"));
    i++; //12
    mvprintw (rrow+i,acol,_("21. isnan"));
    mvprintw (rrow+i,bcol,_("22. fmax"));
    i++; //13
    mvprintw (rrow+i,acol,_("23. fmin"));

    mvprintw(row-2,0,_("select or 0. to Exit: "));
    scanw("%d", &value);
    refresh();
    
    return value;
}

int read_val1 (float *a)
{
	char *pelem=_("Give me the number: ");
	float r;
	
	int row,col;
	
	clear();
	getmaxyx(stdscr,row,col);
	mvprintw ((row/2)-2, (col-strlen(pelem))/2,"%s",pelem);
	scanw("%f", &r);
	*a = r;
	refresh();        
	return 0;
}

int read_val2 (float *b)
{
	char *selem=_("Give me the second number: ");
	int row,col;
	float r;
	
	clear();
	getmaxyx(stdscr,row,col);
	mvprintw ((row/2)-2, (col-strlen(selem))/2,"%s",selem);
	scanw("%f", &r);
	*b = r;
	refresh();        
	return 0;
}


int print_res (float r)
{
	char *resul=_("the result is: ");
	int row,col;
	
	clear();
	getmaxyx(stdscr,row,col);
	mvprintw ((row/2)-2, (col-strlen(resul))/2,"%s %2.2f",resul,r);
	getch();
	refresh();        
	return 0;
}

int print_errordc ()
{
	char *resul=_("Error Division by 0: ");
	int row,col;
	
	clear();
	getmaxyx(stdscr,row,col);
	mvprintw ((row/2)-2, (col-strlen(resul))/2,"%s",resul);
	getch();
	refresh();        
	return 0;
}

int print_not_option ()
{
	char *resul=_("This option is not valid!");
	int row,col;
	
	clear();
	getmaxyx(stdscr,row,col);
	mvprintw ((row/2)-2, (col-strlen(resul))/2,"%s",resul);
	getch();
	refresh();        
	return 0;
}


int addf ()
{
	float a=1,b=1;
	read_val1(&a);
	read_val2(&b);
	print_res (a+b);
	return 0;
}

int subsf ()
{
	float a,b;
	read_val1(&a);
	read_val2(&b);
	print_res (a-b);
	return 0;
}

int mulf ()
{
	float a=1,b=1;
	read_val1(&a);
	read_val2(&b);
	print_res (a*b);
	return 0;
}

int divf ()
{
	float a=1,b=1;
	read_val1(&a);
	read_val2(&b);
	if (b!=0){
		print_res (a/b);
	} 
	else
	{
		print_errordc();
	}
	
	return 0;
}

int sinfu()
{
	float a,r;
	read_val1(&a);
	r=sin(a);
	print_res (r);
	return 0;
}

int cosfu()
{
	float a,r;
	read_val1(&a);
	r=cos(a);
	print_res (r);
	return 0;
}

int tangentfu()
{
	float a,r;
	read_val1(&a);
	r=tan(a);
	print_res (r);
	return 0;
}

int atanfu()
{
	float a,r;
	read_val1(&a);
	r=atan(a);
	print_res (r);
	return 0;
}

int atan2fu()
{
	float a,b,r;
	read_val1(&a);
	read_val2(&b);
	r=atan2(a,b);
	print_res (r);
	return 0;
}

int acosfu()
{
	float a,r;
	read_val1(&a);
	r=acos(a);
	print_res (r);
	return 0;
}

int asinfu()
{
	float a,r;
	read_val1(&a);
	r=asin(a);
	print_res (r);
	return 0;
}

int sqrtfu()
{
	float a,r;
	read_val1(&a);
	r=sqrt(a);
	print_res (r);
	return 0;
}

int powfu()
{
	float a,b,r;
	read_val1(&a);
	read_val2(&b);
	r=pow(a,b);
	print_res (r);
	return 0;
}

int logfu()
{
	float a,r;
	read_val1(&a);
	r=log(a);
	print_res (r);
	return 0;
}

int log10fu()
{
	float a,r;
	read_val1(&a);
	r=log10(a);
	print_res (r);
	return 0;
}

int ldexpfu()
{
	float a,b,r;
	read_val1(&a);
	read_val2(&b);
	r=ldexp(a,b);
	print_res (r);
	return 0;
}

int expfu()
{
	float a,r;
	read_val1(&a);
	r=exp(a);
	print_res (r);
	return 0;
}

int coshfu()
{
	float a,r;
	read_val1(&a);
	r=cosh(a);
	print_res (r);
	return 0;
}

int sinhfu()
{
	float a,r;
	read_val1(&a);
	r=sinh(a);
	print_res (r);
	return 0;
}

int tanhfu()
{
	float a,r;
	read_val1(&a);
	r=tanh(a);
	print_res (r);
	return 0;
}

int isnanfu()
{
	float a,r;
	read_val1(&a);
	r=isnan(a);
	print_res (r);
	return 0;
}

int fmaxfu()
{
	float a,b,r;
	read_val1(&a);
	read_val2(&b);
	r=fmax(a,b);
	print_res (r);
	return 0;
}

int fminfu()
{
	float a,b,r;
	read_val1(&a);
	read_val2(&b);
	r=fmin(a,b);
	print_res (r);
	return 0;
}

int selectv(int s)
{
	char *exmes=_("see you later! ");
	char ex[]="n";
	int row,col;	
	
	getmaxyx(stdscr,row,col);
	
	if (s == 0) {
		clear();
		mvprintw(row/2,(col-strlen(exmes))/2,"%s",exmes);
		scanw("%c", &ex);
		refresh();
	
		}
	else {
		switch(s) {
			case 1:
			addf();
			break;
			case 2:
			subsf();
			break;
			case 3:
			mulf();
			break;
			case 4:
			divf();
			break;
			case 5:
			sinfu();
			break;
			case 6:
			cosfu();
			break;
			case 7:
			tangentfu();
			break;
			case 8:
			atanfu();
			break;
			case 9:
			atan2fu();
			break;
			case 10:
			acosfu();
			break;
			case 11:
			asinfu();
			break;
			case 12:
			sqrtfu();
			break;
			case 13:
			powfu();
			break;
			case 14:
			logfu();
			break;
			case 15:
			log10fu();
			break;
			case 16:
			ldexpfu();
			break;
			case 17:
			expfu();
			break;
			case 18:
			coshfu();
			break;
			case 19:
			sinhfu();
			break;
			case 20:
			tanhfu();
			break;
			case 21:
			isnanfu();
			break;
			case 22:
			fmaxfu();
			break;
			case 23:
			fminfu();
			break;
			default:
			print_not_option();
			break;
			

		}
	}
	return 0;
}


int main(int argc, char **argv)
{
	int v;
	
	//char *elem=_("Give me the operator: ");
	
	
	bind_textdomain_codeset ("calculadora", "UTF-8");
    setlocale(LC_ALL, "");
    bindtextdomain("calculadora", "idioma");
    textdomain("calculadora");
    
    initscr();    
    
    do{
		v=print_menu();
		selectv(v);
		endwin();
		}while(v!=0);
    
    
    
    
    return 0;
}
