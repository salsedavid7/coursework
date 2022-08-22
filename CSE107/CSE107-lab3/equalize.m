function [out] = equalize(image)
%this function makes a histogram of it from image,
%and then equalizes the image  

    original = image;
    [rows,column] = size(image);
    A = compute_histogram(image);
    plot_histogram(A);
    transform = histogram_transform(A);
    transform = round(transform);
    temp = 0;
    for i = 1:rows
        for j = 1:column
            temp = image(i,j) + 1;
            image(i,j) = transform(temp);
        end
    end
    B = compute_histogram(image);
    plot_histogram(B);
    out = B;
    original = double(original);
    original = original(:);
    m = mean(original);
    s = std(original);
    disp("mean original: " + m);
    disp("std original: " + s);
    image = double(image);
    image = image(:);

    me = mean(image);
    se = std(image);
    disp("mean equalized: " + me);
    disp("std equalized: " + se);
