%facts

:- dynamic(room/3).     %adding a new room so it is dynamic
:- dynamic(course/6).   %adding a new course so it is dynamic
:- dynamic(student/3).  %adding a new student so it is dynamic

student(1,[cse321,cse343],hcapped).
student(2,[cse341],hcapped).
student(3,[cse321],_).
student(4,[cse341,cse331],hcapped).
student(5,[cse321,cse343],_).
student(6,[cse331],hcapped).
student(7,[cse341,cse331],_).
student(8,[cse343,cse331],_).
student(9,[cse331],_).
student(10,[cse343],_).
student(11,[cse321,cse343],hcapped).
student(12,[cse331],_).
student(13,[cse343],hcapped).
student(14,[cse331],_).
student(15,[cse343,cse331],_).
student(16,[cse321],_).
student(17,[cse321,cse343],_).



instructor(gozupek,cse321,projector).
instructor(genc,cse341,projector).
instructor(alkan,cse343,smartboard).
instructor(bayrakci,cse331,no).



occupancy(z23,8,cse341).
occupancy(z23,9,cse341).
occupancy(z23,10,cse341).
occupancy(z23,11,cse341).  
occupancy(z23,12,0).
occupancy(z23,13,cse331).
occupancy(z23,14,cse331).
occupancy(z23,15,cse331).
occupancy(z23,16,0).

occupancy(z10,8,cse343).
occupancy(z10,9,cse343).
occupancy(z10,10,cse343).
occupancy(z10,11,cse343).
occupancy(z10,12,0).
occupancy(z10,13,cse321).
occupancy(z10,14,cse321).
occupancy(z10,15,0).
occupancy(z10,16,0).

occupancy(z06,8,0).
occupancy(z06,9,0).
occupancy(z06,10,0).
occupancy(z06,11,0). 
occupancy(z06,12,0).
occupancy(z06,13,0).
occupancy(z06,14,0).
occupancy(z06,15,0).
occupancy(z06,16,0).

occupancy(z11,8,0).
occupancy(z11,9,0).
occupancy(z11,10,0).
occupancy(z11,11,0).
occupancy(z11,12,0).
occupancy(z11,13,0).
occupancy(z11,14,0).
occupancy(z11,15,0).
occupancy(z11,16,0).

room(z06,9,[hcapped,smartboard]).
room(z11,8,[hcapped,smartboard]).
room(z23,12,[hcapped,projector,smartboard]).
room(z10,5,[hcapped,projector]).

course(cse341,genc,3,4,z23,[]).
course(cse343,alkan,4,4,z10,[]).
course(cse331,bayrakci,2,3,z23,[]).
course(cse321,gozupek,3,2,z10,[]).


%rules

% Adding Student,Room and Course.
addStudent(StudentID,CourseList,HCap):-    %adding student dynamically
                                    assertz(
                                        student(StudentID,CourseList,HCap)).
                                
addRoom(RoomID,RoomCapacity,EquipmentRequire):-   %adding room dynamically
                                    assertz(
                                        room(RoomID,RoomCapacity,EquipmentRequire)).

addCourse(CourseID,TeacherID,CourseCapacity,CourseHour,RoomID,List):-   %adding course dynamically
                                    assertz(
                                        course(CourseID,TeacherID,CourseCapacity,CourseHour,RoomID,List)).


conflict(CourseID1,CourseID2):- occupancy(_,Hour,CourseID1), %hold the hour of CourseID1
    							occupancy(_,Hour,CourseID2) %hold the hour of CourseID2
    							,\+ CourseID1==CourseID2,!. %if there is equality return true.If not return false.

assign(RoomID,CourseID):-
                        course(CourseID,TeacherID,LessonCapacity,_,_,_),
                        instructor(TeacherID,_,EquipmentRequire),    %required the equipment by instructor
                        room(RoomID,RoomCapacity,Equipment), %room capacity should bigger or equal than course capacity
                        (RoomCapacity >= LessonCapacity, (EquipmentRequire == no ; member(EquipmentRequire,Equipment))).

enroll(StudentID,CourseID):-                                                %Check whether a student can be enrolled to a given class.
                                                                            %Check which classes a student can be assigned.
                                student(StudentID,CourseList,Handicapped),  % I hold the student information
                                course(CourseID,_,_,_,RoomID,_),            %I hold the course information
                                room(RoomID,_,Equipment),                   %I hold the room information
                                member(Handicapped,Equipment),
                                \+ courseConf(CourseID,CourseList).

courseConf(CourseID,[HEAD|TAIL]):-          %I find the conflict courses by recursively
                    conflict(CourseID,HEAD);
                    courseConf(CourseID,TAIL).


