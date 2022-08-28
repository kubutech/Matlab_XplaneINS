elevGPS = coordinates(7,:);
elevINS = coordinates(4,:);
latGPS = coordinates(5,:);
latINS = coordinates(2,:);
lonGPS = coordinates(6,:);
lonINS = coordinates(3,:);
time = coordinates(1,:);

figure();
plot(time, elevINS, time, elevGPS);
legend("GPS", "INS");

figure();

worldmap 'world';
[latlim,lonlim] = geoquadline(latINS,lonINS);
buf = 10;
[latlim,lonlim] = bufgeoquad(latlim,lonlim,buf,buf);
ax = worldmap(latlim,lonlim);
oceanColor = [.5 .7 .9];
setm(ax,'FFaceColor',oceanColor);
geoshow('landareas.shp','FaceColor',[0.5 0.7 0.5]);
geoshow('worldrivers.shp','Color', 'blue');
geoshow('worldcities.shp','Marker','.','Color','red');
geoshow(latGPS,lonGPS,'Color','y');
hold on;
geoshow(latINS,lonINS,'Color','m');
axis on
clear latlim lonlim oceanColor lonX lonZ latX latZ buf ax;
