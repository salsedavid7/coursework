%function to plot the histogram for the normalized histogram
function plot_histogram(h)
    %plot the bar
    bar(histogram);
    %set the x-axis values
    x = 1:256;
    %set the y-axis values
    y = h;
    %set the axies
    bar(x,y);
    %label the x-axis
    xlabel("intensity value");
    %label the y-axis
    ylabel("PMF");  

end
