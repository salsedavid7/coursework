inImage =uint8([255,255,255,255,255,255,255,243,210,156,121,111,110,111,122,157,209,244,254,255,255,255,255,255,255,255,255,255,255,255,254,243,210,155,122,111,110,111,111,112,122,156,210,243,254,255,255,255,255,255;255,255,255,255,255,255,253,240,194,123,76,62,61,62,77,122,195,239,253,255,255,255,254,255,255,255,255,255,255,255,253,240,193,123,77,62,61,61,61,62,76,122,194,240,254,255,255,255,255,255;255,255,255,255,255,255,253,238,190,111,62,48,47,48,62,112,189,239,254,255,255,255,255,255,255,255,255,255,255,255,253,238,190,112,62,48,46,46,46,48,62,111,190,238,252,254,255,255,255,255;255,255,255,255,255,255,253,238,189,111,62,46,44,47,61,111,189,239,253,255,255,255,255,255,255,255,255,255,255,255,253,238,189,110,61,47,44,44,45,47,61,110,189,238,253,255,255,255,255,255;255,255,255,255,255,255,253,239,189,111,61,47,45,46,61,110,189,238,253,255,255,255,255,255,255,255,255,255,255,255,253,238,189,110,61,46,44,44,45,46,61,110,189,238,253,255,255,255,255,255;255,255,255,255,254,255,253,238,189,111,61,46,44,46,61,110,189,239,253,255,255,255,255,255,255,255,255,255,255,255,253,238,189,110,61,46,45,45,44,46,61,110,189,238,253,255,255,255,255,255;255,255,255,255,255,255,253,238,189,111,61,46,44,46,61,110,189,239,253,255,255,255,255,255,255,255,255,255,255,255,253,238,189,110,61,47,45,44,44,47,61,110,189,238,253,255,255,255,255,255;254,253,253,253,253,253,251,237,188,109,61,47,45,46,61,110,188,236,251,253,253,253,253,253,253,253,253,253,253,253,251,237,188,110,61,46,44,45,45,47,61,110,188,237,252,253,253,253,253,254;243,241,238,239,238,238,236,223,178,105,60,46,44,46,60,105,177,224,236,238,239,238,239,238,238,238,238,238,238,238,236,223,178,105,61,46,45,45,45,47,60,105,178,223,236,238,239,238,240,243;211,195,190,189,188,189,187,178,143,90,56,45,44,45,56,90,144,178,187,189,189,189,189,189,189,189,189,189,189,189,187,178,143,90,56,45,45,44,44,46,56,90,143,177,187,189,189,189,195,210;157,123,113,112,111,112,111,106,91,66,50,46,45,45,50,66,90,107,112,112,112,112,111,112,112,112,112,111,112,112,111,106,91,66,49,45,45,44,44,45,49,65,91,107,112,112,112,113,123,157;133,91,79,78,77,77,77,75,67,55,47,45,44,45,47,55,67,75,77,77,77,77,77,77,77,77,77,77,78,77,77,75,67,55,48,45,45,44,44,44,48,55,67,75,76,77,77,79,92,132;156,123,113,112,112,112,112,107,91,66,50,45,44,45,49,66,91,107,111,112,112,112,112,112,112,112,112,112,112,112,112,107,91,65,49,45,44,45,44,45,49,65,90,107,111,112,112,113,122,157;210,194,189,189,189,189,188,178,144,91,56,45,44,45,56,90,144,177,187,189,189,189,189,189,189,189,189,189,189,189,187,178,144,90,56,46,44,45,44,46,56,90,143,178,188,189,189,190,195,210;244,240,238,238,238,238,236,223,178,105,60,47,45,46,60,105,178,223,237,239,238,238,238,238,238,238,238,239,239,239,236,223,177,105,59,46,45,45,45,46,60,105,178,223,237,238,238,239,241,243;254,254,252,253,253,253,250,237,188,109,61,46,44,47,61,110,188,237,251,253,253,253,253,253,253,253,252,253,253,253,252,237,188,109,61,47,44,44,45,46,61,109,188,236,251,253,253,253,253,254;255,255,255,255,255,255,253,238,189,110,61,46,44,46,61,110,189,238,253,255,255,255,255,254,255,255,255,255,255,255,253,238,188,110,61,46,44,44,44,46,61,110,189,238,253,255,255,255,255,255;255,255,255,255,255,255,253,238,190,111,61,46,44,46,61,110,189,238,253,255,255,255,255,255,255,255,255,255,255,255,253,239,189,110,61,46,44,44,45,47,62,110,189,238,253,255,255,255,255,255;255,255,255,255,255,255,253,238,189,110,61,47,44,46,61,111,189,238,253,255,255,255,255,255,255,255,255,255,255,255,253,239,189,110,61,46,44,45,44,46,61,110,189,238,253,255,255,255,255,255;255,255,255,255,255,255,253,238,189,111,61,47,44,46,61,111,189,238,253,255,255,255,255,255,255,255,255,255,255,255,253,238,189,111,61,46,44,45,44,46,61,110,189,239,253,255,255,255,255,255;255,255,255,255,255,255,253,238,188,110,61,47,45,46,61,110,190,239,253,255,255,255,255,255,255,255,255,255,255,255,253,239,189,111,61,47,44,44,44,46,61,110,189,238,253,255,255,255,255,255;255,255,255,255,255,255,253,238,189,110,61,47,45,47,61,110,189,238,254,255,255,255,255,255,255,255,255,255,255,255,253,239,189,110,61,47,45,44,44,47,61,110,189,238,253,255,255,255,255,255;254,253,252,253,253,253,251,237,187,110,61,46,44,47,61,110,188,237,251,253,253,253,253,253,253,253,253,253,253,253,251,237,187,110,61,46,44,44,44,46,61,110,188,237,251,253,253,253,253,254;243,240,238,238,238,238,236,223,178,105,60,47,44,47,60,106,178,224,236,238,239,238,238,238,238,238,238,238,239,239,236,222,178,105,60,47,44,45,45,46,60,105,178,223,236,238,238,238,240,243;209,195,190,189,189,189,188,178,143,90,56,46,45,45,56,89,144,178,188,188,189,189,189,189,189,189,189,189,189,189,188,178,143,90,56,46,44,45,44,45,56,91,144,177,188,189,189,190,195,210;156,122,112,111,110,110,110,105,90,65,50,45,45,45,49,66,89,105,110,111,111,110,111,111,110,111,111,110,110,110,110,105,90,64,50,46,44,44,45,45,49,65,90,105,110,110,110,111,121,156;123,76,63,61,61,62,61,59,55,49,46,44,44,45,46,49,56,59,61,61,61,62,61,61,61,61,61,61,61,61,61,60,55,49,45,44,44,44,45,44,45,49,55,59,61,62,61,62,76,122;111,63,48,46,46,47,47,46,46,45,44,44,44,44,45,45,45,46,47,46,46,47,46,47,47,46,46,46,47,46,46,46,46,46,44,44,45,44,45,45,44,45,46,46,47,47,46,47,62,111;111,62,46,45,45,44,44,44,44,45,45,45,45,44,45,44,45,45,45,45,44,44,44,45,45,44,44,44,44,44,44,44,44,44,44,45,45,44,44,45,44,45,44,44,44,44,45,47,61,111;111,61,47,45,45,45,44,44,44,44,45,44,44,45,45,45,44,44,44,45,45,45,45,44,45,45,44,45,44,44,44,44,45,44,44,45,44,45,44,45,44,44,44,44,44,44,45,46,61,110;110,61,47,44,44,45,45,44,45,44,44,45,45,45,44,44,44,44,45,44,44,45,45,44,44,45,44,45,44,44,44,45,44,44,45,45,44,44,44,45,45,44,44,45,44,45,45,47,61,110;110,61,46,44,45,44,44,45,45,45,44,44,44,44,45,45,44,44,45,44,45,44,44,45,44,45,44,44,45,44,44,44,44,44,44,45,44,45,44,44,45,44,44,44,44,45,44,47,61,110;110,61,46,45,44,44,44,45,44,44,44,44,44,44,45,44,45,45,44,44,44,44,44,44,45,44,44,44,44,44,44,44,45,44,45,44,44,45,44,45,44,44,44,44,44,44,44,47,61,111;110,61,46,44,44,45,44,44,44,44,45,44,45,45,45,44,44,44,44,44,44,44,44,44,44,44,44,44,44,45,45,45,45,44,44,45,45,44,44,45,45,45,45,44,44,44,44,46,61,111;111,61,46,44,44,44,44,44,45,44,44,45,45,44,44,44,44,44,45,45,45,45,44,44,44,44,45,44,44,45,45,45,45,45,44,44,44,45,45,44,45,44,44,44,44,44,45,46,61,111;111,61,46,45,44,44,45,45,45,45,44,44,44,45,45,44,44,44,44,44,44,44,45,45,44,44,44,44,45,45,44,44,44,45,45,45,45,45,44,45,45,45,45,44,45,45,45,46,61,111;110,61,47,45,44,44,45,44,44,45,44,45,45,44,45,44,45,44,45,45,44,44,44,44,44,44,44,45,45,45,45,45,45,45,44,44,44,44,44,45,44,45,45,44,44,44,44,46,61,110;112,62,47,47,47,46,47,46,46,45,45,45,45,44,45,45,46,46,46,47,47,46,46,46,46,46,46,47,46,46,47,46,45,45,45,44,44,45,44,44,45,45,45,46,47,47,46,47,62,112;122,77,62,62,62,61,61,59,55,49,46,45,44,45,45,49,55,60,61,61,61,61,61,61,61,61,61,62,61,61,61,59,56,49,46,45,44,45,45,45,46,50,56,59,60,61,62,62,76,123;156,121,112,110,110,110,110,105,90,65,49,45,45,45,49,65,90,104,110,110,111,110,111,110,111,111,111,111,110,111,110,105,89,65,49,45,44,45,44,46,49,66,89,105,110,110,111,112,121,156;209,196,189,189,189,189,188,178,143,90,56,45,44,45,56,90,143,179,187,189,189,189,189,189,189,189,189,189,189,189,188,178,144,89,56,45,44,45,45,46,56,90,145,177,187,189,189,190,195,210;244,240,239,238,238,239,237,223,178,106,60,46,45,47,60,106,179,223,236,239,238,238,238,238,238,238,238,238,239,238,236,224,177,106,60,46,45,44,44,47,60,106,177,223,237,238,238,238,240,244;253,253,253,253,253,253,251,236,188,109,61,46,45,48,61,110,187,236,252,253,253,253,253,253,253,253,253,253,253,254,251,236,188,110,60,46,44,44,44,46,61,110,188,236,250,252,253,253,253,254;255,255,255,255,255,255,252,239,189,111,62,46,44,46,61,111,189,239,253,254,255,255,255,255,255,255,255,255,255,255,253,238,188,110,61,47,44,45,45,46,61,111,189,239,253,255,255,255,254,255;254,255,255,255,255,255,253,238,189,111,61,47,45,46,61,110,189,238,253,255,255,255,255,255,255,255,255,255,255,255,253,239,189,110,61,46,44,45,45,47,61,111,189,238,253,255,255,255,255,255;255,255,255,255,254,255,253,238,189,111,61,46,44,47,61,110,189,238,253,255,255,254,255,255,255,255,255,255,255,255,253,238,189,110,61,46,45,45,44,46,61,111,189,239,253,255,255,255,255,255;255,255,255,255,255,255,253,238,189,110,61,46,44,46,61,111,189,238,253,255,255,255,255,255,255,255,255,255,255,255,253,238,189,111,61,46,44,45,45,46,61,111,189,238,253,255,255,255,255,255;255,255,255,255,255,255,253,239,190,111,62,48,46,48,62,111,189,238,253,255,255,255,255,255,255,255,255,255,255,255,254,239,190,112,62,47,46,46,46,48,63,111,189,238,253,255,255,255,255,255;255,255,255,255,255,255,253,240,194,122,76,62,61,62,76,122,194,240,253,255,255,255,255,255,255,255,255,255,255,255,253,240,194,123,76,62,61,61,61,62,76,122,194,240,253,255,255,255,255,255;255,255,255,255,255,255,254,243,210,156,121,111,111,112,122,156,209,243,254,255,255,255,255,255,255,255,255,255,255,255,254,243,210,156,122,112,110,110,111,111,121,156,210,243,254,255,255,255,255,255]);
outImage = halftone(inImage);

%show original image
subplot(121);
imshow(inImage);

%show halftoned image
subplot(122);
imshow(outImage);





