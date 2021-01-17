module Jekyll
    class BojDifficultyInlineTag < Liquid::Tag
        LOWER_DIFF = ['ruby', 'diamond', 'platinum', 'gold', 'silver', 'bronze']
        CAMEL_DIFF = ['Ruby', 'Diamond', 'Platinum' ,'Gold', 'Silver', 'Bronze']
        ROMAN = ['Ⅰ', 'Ⅱ', 'Ⅲ', 'Ⅳ', 'Ⅴ']
        CIRCLE_NUM = ['①', '②', '③', '④', '⑤']

        def initialize(tag_name, input, tokens)
            super
            inputs = input.split()
            @diff = inputs[0]
            if inputs.length() == 2
                if inputs[1] == "full"
                    @mode = 1
                elsif inputs[1] == "abbr"
                    @mode = 2
                else inputs[1] == "default"
                    @mode = 0
                end
            else
                @mode = 0
            end
        end

        def render(context)
            output = ""

            unless @diff.is_a? Integer
                @diff = context[@diff]
            end

            if @mode == 0
                if @diff == 0
                    output += "<span class='diff_unrated'>Unrated</span>"
                else
                    output += "<span class='diff_#{BojDifficultyInlineTag::LOWER_DIFF[(@diff - 1) / 5]}'>#{BojDifficultyInlineTag::CAMEL_DIFF[(@diff - 1) / 5]} #{BojDifficultyInlineTag::ROMAN[(@diff - 1) % 5]}</span>"
                end
            elsif @mode == 1
                if @diff == 0
                    output += "<span class='diff_unrated'>？</span>"
                else
                    output += "<span class='diff_#{@LOWER_DIFF[(@diff - 1) / 5]}'>#{BojDifficultyInlineTag::CIRCLE_NUM[(@diff - 1) % 5]}</span>"
                end
            elsif @mode == 2
                if @diff == 0
                    output += "<span class='diff_unrated'>？ Unrated</span>"
                else
                    output += "<span class='diff_#{@LOWER_DIFF[(@diff - 1) / 5]}'>#{BojDifficultyInlineTag::CIRCLE_NUM[(@diff - 1) % 5]} #{BojDifficultyInlineTag::CAMEL_DIFF[(@diff - 1) / 5]} #{BojDifficultyInlineTag::ROMAN[(@diff - 1) % 5]}</span>"
                end
            end

            return output
        end
    end
end

Liquid::Template.register_tag("boj_diff", Jekyll::BojDifficultyInlineTag)