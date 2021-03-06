#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Modifier.h"
#include <vector>

//XOR is # true % 2, MAJOR is at least 50%, MINOR is less than 50%
//XOR, MAJOR and MINOR has a bit more resource intensive, as they always check every one.
enum LogicOperators{AND, NAND, OR, NOR, XOR, MAJOR, MINOR};


enum ValueOperators{NOT_EQUAL, EQUAL, GREATER, LESSER};


template <typename T> class Conditional
{
   public:
      /** Default constructor */
      Conditional();
      /** Default destructor */
      virtual ~Conditional();

      bool checkConditional();
      void addConditional(Conditional newConditional);

      void addLocationModifer(); //TODO: All these functions
      //void addGlobalModifer(Modifier temp);

      void addComparedValue(T* newValue);
      void addWatchedValue(T* watchedValue);

      void changeLogicOp(LogicOperators newOp);
      void changeValueOp(ValueOperators newOp);

      bool evaluate();



   protected:
   private:
      std::vector <Conditional> Conditionals;

      LogicOperators currentLogicOP;
      ValueOperators currentValueOp;
      //T comparedValue;
      T* watchedValue; //This is what is compared with the stored Value.
      T* comparedValuePointer; //This should point to either a constant, or a "meta" variable. (point it to # of bases, or something)





};

#endif // CONDITIONAL_H
