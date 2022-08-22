function [theta_out, rho_out, accumulator] = hough_transform(i_edge)

    %rows and columns of input image
	M = size(i_edge,1); 
    N = size(i_edge,2);
    
    %get diagonal size of image
    D = sqrt(M.^2 + N.^2);
    
    %rounds as size inputs must be integers
    D = round(D);
    
    %set accumulator matrix with 2*D+1 rows and 180 columns
    accumulator = zeros([2*D+1 180]);
    
    %initializing theta rho highest value to find maximum value in accumulator
    theta_out = 0;
    rho_out = 0;
    max_val = 0;
    
    %hough transform algorithm
    for i = 1:M
        for j =1:N
            
            %detects a white pixel in i_edge
            if(i_edge(i,j) == 255)
                
                %theta values from -89 to 90
                for theta = -89:90
                    
                    %calculate rho with normal representation of line
                    rho = i*cosd(theta)+j*sind(theta);
                    
                    %accomodates rounding
                    rho = round(rho);
                    
                    %saving occurences of rho and theta.
                    %accumulator mat of (-89,x) doesn't
                    %exist so:
                    %rho+D+1 because rho: -D < rho < D
                    %theta+90 because theta: -89 < theta < 90
                    accumulator(rho+D+1,theta+90) = accumulator(rho+D+1,theta+90) + 1;
                    
                end 
            end
        end
    end
    
    %find max value w/in accumulator
    for i = 1: size(accumulator,1)
        for j = 1: size(accumulator,2)
            
            %compare values to max val
            if(accumulator(i,j) > max_val)
            
                %set corresponding values to output
                max_val = accumulator(i,j);
                
                %revert back to original value
                theta_out = j-90;
                rho_out = i-D-1;
            
            end
        end
    end
    
end


