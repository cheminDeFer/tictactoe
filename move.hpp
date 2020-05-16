#ifndef MOVE_H
#define MOVE_H

class Move
{
public:
  Move(int squareToDraw);
  ~Move();
private:
  bool isValid;
  int squareToDraw;
  
  
};


#endif /* MOVE_H */
