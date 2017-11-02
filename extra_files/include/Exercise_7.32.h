#ifndef Exercise_7_32_h
#define Exercise_7_32_h

#include<string>
#include<vector>
#include<iostream>

class Screen;

class Window_mgr{
   public:
      using ScreenIndex = std::vector<Screen>::size_type;
      inline void clear(ScreenIndex i);
   private:
      std::vector<Screen> screens{Screen(24,80,' ')};
};

class Screen{
   friend void Window_mgr::clear(ScreenIndex i);
   public:
      using pos = std::string::size_type;
      
      Screen() = default;
      Screen(pos ht, pos wd):height(ht),width(wd),contents(ht*wd,' ') {}
      Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd,c) {}
      
      char get() const {return contents[cursor];}
      char get(pos r, pos c) const {return contents[r*width+c];}
      inline Screen& move(pos r, pos c);
      inline Screen& set(char c);
      inline Screen& set(pos r, pos c, char ch);

      const Screen& display(std::ostream &os) const {do_display(os); return *this;}
      Screen& display(std::ostream &os) {do_display(os); return *this;}

   private:
      void do_display(std::ostream &os) const {os << contents;}
   private:
      pos cursor = 0;
      pos height = 0, width = 0;
      std::string contents;
};

Screen& Screen::move(pos r, pos c)
{
   pos row = r*width;
   cursor = row + c;
   return *this;
}

Screen& Screen::set(char c)
{
   contents[cursor] = c;
   return *this;
}

Screen& Screen::set(pos r, pos c, char ch)
{
   contents[r*width+c] = ch;
}

void Window_mgr::clear(ScreenIndex i)
{
   if(i>=screens.size()) return;
   Screen &s = screens[i];
   s.contents = string(s.height*s.width, ' ');
}

#endif

