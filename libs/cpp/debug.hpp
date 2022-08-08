#pragma once //INCLUDE GUARD

//INCLUDE DEPENDINGS
#include <string>
#include <iostream>
#include <map>
#include <chrono>
//INCLUDE DEPENDINGS

namespace Yourein{
    class Timer{
        private:
            std::chrono::system_clock::time_point starttime, endtime;

        public:
            void start(){
                starttime = std::chrono::system_clock::now();
            }

            void end(){
                endtime = std::chrono::system_clock::now();
            }

            double in_mseconds(){
                return std::chrono::duration_cast<std::chrono::milliseconds>(endtime-starttime).count();
            }

            double in_seconds(){
                return std::chrono::duration_cast<std::chrono::seconds>(endtime - starttime).count();
            }

            double in_minutes(){
                return (std::chrono::duration_cast<std::chrono::seconds>(endtime - starttime).count())/double(60);
            }
    };

    namespace debug{
        template <typename T>
        void debug_a(const T &a){
            for (auto x:a){
                std::cerr << x << " ";
            }
            std::cerr << std::endl;
        }

        template <>
        void debug_a(const std::string &a){
            std::cerr << a << std::endl;
        }

        template <typename T1, typename T2>
        void debug_a(const std::map<T1, T2> &a){
            for (auto x : a){
                std::cerr << x.first << " : " << x.second << std::endl;
            }
        }
    }
}