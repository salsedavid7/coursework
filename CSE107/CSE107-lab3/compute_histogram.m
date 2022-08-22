%function h to compute the normalized histogram for grayscale image which
%returns the vector form of the normalized histogram
function h = compute_histogram(image)

    %gets the size of the grayscale image
    [rows, columns] = size(image);
    %initializing an empty vector
    h = zeros(1, 256);

    %loop through rows
    for i = 1 : rows
        % loop thru columns
        for j = 1 : columns
            %gets the intensity of the pixel
            value = double(image(i, j));
            value = value + 1;

            %compute frequency of the pixel
            h(value) = h(value) + 1;
        end
    end
    
    a = 0;
    for i = 1:256
        a = a + h(i);
    end
    h = h / a;

end
