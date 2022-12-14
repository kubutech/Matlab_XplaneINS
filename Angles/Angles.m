classdef Angles < matlab.System & coder.ExternalDependency
        % Angles- this block sends its inputs to active X-Plane simulation using shared memory. Note: in order for this block to work, special X-Plane plugin needs to be installed
    
        properties(Access = public)
        
        end
            
        properties(DiscreteState)
    
        end
    
        properties(Access = private)
    
        end
    
        methods(Access = protected)
            function setupImpl(obj)
                    coder.cinclude('Angles.h');
                    coder.ceval('setup_Angles');
            end
    
            function [pitch,true_heading,roll] = stepImpl(obj)
                pitch = single(0);
                true_heading = single(0);
                roll = single(0);
                coder.cinclude('Angles.h');
                coder.ceval('update_Angles');
                pitch = coder.ceval('get_pitch');
                true_heading = coder.ceval('get_true_heading');
                roll = coder.ceval('get_roll');
            end
    
            function resetImpl(obj)
                
            end
            
            function releaseImpl(obj)
                coder.cinclude('Angles.h');
                coder.ceval('close_Angles');
            end
        end
            
        methods (Static)
            function name = getDescriptiveName()
                name = 'Angles';
            end
            function b = isSupportedContext(context)
                b = context.isCodeGenTarget('rtw');
            end
            function updateBuildInfo(buildInfo, context)
            % Update the build-time buildInfo
                blockRoot = fileparts(mfilename('fullpath'));
                buildInfo.addIncludePaths({blockRoot});
                buildInfo.addIncludeFiles({'Angles.h'});
                buildInfo.addSourcePaths({blockRoot});
                buildInfo.addSourceFiles({'Angles.c'});
            end
        end
    end