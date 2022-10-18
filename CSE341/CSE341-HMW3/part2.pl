% facts

flight(canakkale,erzincan,6).
flight(erzincan,canakkale,6).

flight(erzincan,antalya,3).
flight(antalya,erzincan,3).

flight(antalya,izmir,2).
flight(izmir,antalya,2).

flight(antalya,diyarbakir,4).
flight(diyarbakir,antalya,4).

flight(izmir,istanbul,2).
flight(istanbul,izmir,2).

flight(izmir,ankara,6).
flight(ankara,izmir,6).

flight(istanbul,ankara,1).
flight(ankara,istanbul,1).

flight(istanbul,rize,4).
flight(rize,istanbul,4).

flight(ankara,diyarbakir,8).
flight(diyarbakir,ankara,8).

flight(ankara,rize,5).
flight(rize,ankara,5).

flight(ankara,van,4).
flight(van,ankara,4).

flight(van,gaziantep,3).
flight(gaziantep,van,3).

% rules

direct_route(X,Y,C) :- flight(X,Y,C).
route(X,Y,C) :- record_route(X,Y,C,[]).   % record the visited cities.

record_route(X,Y,C,V) :-  % recursive
                \+ member(X,V),    % check x not visited before
                flight(X,Z,K),
                (Y = Z , C is K;
                record_route(Z,Y,M,[X|V]),    %I record the connected route
                X \=Y , C is K + M).          %I sum the connected routes.