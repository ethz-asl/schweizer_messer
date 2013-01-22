function saveMatrixArchive( filename, ma, append )
%SAVEMATRIXARCHIVE Saves the fields of a struct as an asrl mat archive
%  
% Input:
% filename - the name of the archive to save
% ma       - a struct with matrices for fields. For each field, the matrix will
%            be saved in an asrl matrix archive given by filename
% append   - optional parameter. If true, the data is appended to the file
%

startMagic = 'A';
endMagic   = 'B';
nameFixedSize = 32;
nameFormatSpec = sprintf('%%%ds',nameFixedSize);

if nargin < 3
    append = false;
end



% Verify the field names
names = fieldnames(ama);

fprintf('Saving an archive with %d matrices\n',length(names));
for i = 1:length(names)
    if length(names{i}) > nameFixedSize
        error('The name \"%s\" is too long. Maximum name length: %d',names{i},nameFixedSize);
    end
    name = names{i};
    for c = name
       if ~(isletter(c) | (( '0' <= c ) & ( c <= '9' )) | c == '_')
           error('All characters in a field name must be letters or numbers. Field %s failed', name);
       end
    end
end

if append
    openMode = 'a+';
else
    openMode = 'w+';
end

% Now that the field names have been verified, open the archive.
[fid, message] = fopen(filename,openMode,'ieee-le');
if fid == 0
    error('unable to open file %s for writing: %s',filename, message);
end

try 
    for i = 1:length(names)
        name = names{i};
        M = ama.(name);
        
        
        
        if ~(islogical(M) || isnumeric(M)) | isempty(M)
            error('Matrix Archives can only save double matrices. Field %s failed', name);
        end
        % Magic number to start.
        fwrite(fid,startMagic,'uint8');
        
        % Write the name
        paddedName = sprintf( nameFormatSpec, name );
        fwrite(fid,paddedName,'uint8');
        
        % 32bit rows and cols.
        sz = size(M);
        if length(sz) < 1 || length(sz) > 2
            error('Matrix %s has an unsupported number of dimensions %d. Only 1 or 2 are supported',name, length(sz));
        end
        
        fprintf('Saving matrix %s with size (%d, %d)\n',name,size(M,1),size(M,2));
        
        if length(sz) == 1
            sz = [sz 1];
        end
   
        fwrite(fid,sz,'uint32');
        
        % Now write the data.
        fwrite(fid,M,'double');
        
        % Now the magic end character
        fwrite(fid,endMagic,'uint8');
        
    end
    fclose(fid);
catch ME
    fclose(fid);
    rethrow(ME);
end


end

