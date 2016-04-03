clear;

pomiary = fscanfMat('pomiary.dat');
ilosc_pomiarow = pomiary(1, 1);
ilosc_obiektow = pomiary(1, 2);

rozmiary = pomiary(2:(ilosc_obiektow*ilosc_pomiarow+1), 1);
czasy = pomiary(2:(ilosc_obiektow*ilosc_pomiarow+1), 2);

kolory = ['r' 'g' 'b' 'k'];

for i=1:ilosc_obiektow
    plot(rozmiary((1+(i-1)*ilosc_pomiarow):(i*ilosc_pomiarow)), czasy((1+(i-1)*ilosc_pomiarow):(i*ilosc_pomiarow)), kolory(modulo(i-1, 4)+1) + '-');
end
legend(['tab x2' 'stl' 'lab02'], 2)
xlabel('Ilosc danych');
ylabel('Czas dodania [us]');
