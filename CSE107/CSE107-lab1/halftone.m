function out = halftone(in)

[row_of_in, col_of_in] = size(in);

out = uint8(ones(row_of_in, col_of_in));

%initialize dot patterns

dots = uint8(zeros(3,3,10));

dots(:,:,1) = [0 0 0; 0 0 0; 0 0 0];
dots(:,:,2) = [0 255 0; 0 0 0; 0 0 0];
dots(:,:,3) = [0 255 0; 0 0 0; 0 0 255];
dots(:,:,4) = [255 255 0; 0 0 0; 0 0 255];
dots(:,:,5) = [255 255 0; 0 0 255; 255 0 255];
dots(:,:,6) = [255 255 255; 0 0 0; 255 0 255];
dots(:,:,7) = [255 255 255; 0 0 255; 255 0 255];
dots(:,:,8) = [255 255 255; 0 0 255; 255 255 255];
dots(:,:,9) = [255 255 255; 255 0 255; 255 255 255];
dots(:,:,10) = [255 255 255; 255 255 255; 255 255 255];



%determines if row or column is multiple of 3
r_edge = mod(row_of_in, 3);
c_edge = mod(col_of_in, 3);


for r1 = 1:3:(row_of_in - r_edge)
    for c1 = 1:3:(col_of_in - c_edge)
        
        avg =  mean(mean((in(r1:r1+2,c1:c1+2))));   
        index = floor((avg/255) * 10);
        disp(index)
       
        if index == 10
            index = 9;
        end
         
        out(r1:r1+2, c1:c1+2) = dots(:,:,index+1);
      
    end
    
end
     %if c_edge > 0 & r_edge > 0 then
end