function [ ocam_model ] = getCam( tag )

if tag == 'A'
    % The forward polynomial coefficients
    ocam_model.ss = [-2.553268e+002 0.000000e+000 1.377842e-003 -1.086995e-006 3.602934e-009];  
    % The inverse polynomial coefficients
    ocam_model.pol = [407.969458 261.507464 7.853929 27.715515 23.682018 2.354540 3.812054 7.456285 -0.481419 -2.287444 1.332880 1.635385 0.379181];
    ocam_model.xc = 617.241028;
    ocam_model.yc = 510.306277;
    ocam_model.width = 1224;
    ocam_model.height = 1024;
    ocam_model.c = 0.999967 ;
    ocam_model.d = -0.000213 ;
    ocam_model.e = -0.000217;
elseif tag == 'B'
    % The forward polynomial coefficients
    ocam_model.ss = [-2.536856e+002 0.000000e+000 1.378466e-003 -1.218599e-006 3.927661e-009];  
    % The inverse polynomial coefficients
    ocam_model.pol = [406.826612 258.401991 3.342864 27.504761 24.533945 0.344968 3.572702 8.889182 -0.659627 -3.087009 1.258937 1.799974 0.423675];
    ocam_model.xc = 600.132206;
    ocam_model.yc = 505.312127;
    ocam_model.width = 1224;
    ocam_model.height = 1024;
    ocam_model.c = 1.000678 ;
    ocam_model.d = -0.000043;
    ocam_model.e = -0.000034;
else
    error('Unknown tag %s', tag);
end

% I believe these guys are flipped in the evaluation functions.
ocam_model.pol = fliplr(ocam_model.pol);
ocam_model.ss = fliplr(ocam_model.ss);
        

end

